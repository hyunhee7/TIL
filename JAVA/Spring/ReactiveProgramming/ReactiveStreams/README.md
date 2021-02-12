# Reactive Streams

[토비의봄TV 6화 스프링 리액티브 프로그래밍](https://youtu.be/8fenTR3KOJo) 을 바탕으로 정리한 글입니다.  

.

> 목표

Duality(쌍대성)과 Observer Pattern을 통해 ReactiveProgramming이 무엇인지 알아보자.

## Duality

Iterable과 Observable은 Duality(쌍대성) 관계를 갖고있다. 아래 Iterable로 구현한 코드(Pull방식)와 Observable(Push방식)으로 구현한 코드를 비교하며 양립하는 Duality 관계를 알아보자.

### Iterable

-   for loop를 사용할 수 있는 이유는 Iterable 때문이다.
-   Pull 방식 - it.next()로 value를 끌어오는 방식

```java
Iterable<Integer> iter = Arrays.asList(1,2,3,4,5);
for (Integer i : iter) {
    System.out.println(i);
}
```

즉, for Each는 Iterable 때문임을 기억하고 넘어가자.

```java
Iterable<Integer> iter = () ->
    new Iterator<>() {
        int i=0;
        final static int MAX = 10;

        public boolean hasNext() {
            return i < MAX;
        }

        public Integer next() {
            return ++i;
        }
    };

for (Integer i : iter) {
    System.out.println(i);
}
```

### Observable

> Observer 패턴

-   Observable(Publisher, 발행자) - 새로운 정보 발생 시, 이벤트(Data)를 제공. Observer에 notify한다.
-   Observer(Subscriber, 구독자, 관찰자) - notify를 받는 역할. Observable에 해당 Observer를 등록한다.
-   push 개념 - 주는 방식.

```java
static class IntObservable extends Observable implements Runnable{

    @Override
    public void run() {
        for (int i=1; i<=10; i++){
            setChanged();
            notifyObservers(i);     // : push방식 <--> int i = it.next(); // : pull 방식
        }
    }
}

public static void main(String[] args) {
    Observer ob = new Observer() {
        @Override
        public void update(Observable o, Object arg) {
            System.out.println(Thread.currentThread().getName()+ " " + arg);
        }
    };

    IntObservable io = new IntObservable();
    io.addObserver(ob);

    //외부 스레드에서 수행되도록 처리
    ExecutorService es = Executors.newSingleThreadExecutor();
    es.execute(io);

    System.out.println(Thread.currentThread().getName() + " EXIT");
    es.shutdown();
}

```

## Observer패턴의 당시 문제

널리 알려진 옵저버 패턴에서 몇가지 문제를 꼽자면 이러하다.

1.  Complete
2.  Error  
    이 두가지 처리를 어떻게 해결할 수 있을까에 대한 해답으로 나온 것이 Reactive Programming의 시초이다.

## Reactive Streams

위와 같은 문제를 어떻게 해결하면 좋을까? 라는 질문에서 Reactive Streams가 생겨났다.

### Component

-   Publisher  
    이벤트(데이터)를 제공하는 쪽.  
    subscribe 메서드에서 onSubscribe를 반드시 호출해주어야 한다. (코드 참조)
    
-   Subscriber  
    이벤트(데이터)를 받아서 처리하는 쪽.  
    onSubscribe, onNext, onError, onComplete 메서드가 있다. (코드참조)  
    onSubscribe는 항상 호출해야한다.
    
-   Subscription  
    Subscriber가 이벤트(데이터) 처리 할 때 속도 조절을 할 수 있도록 하는 request, cancel 등의 메서드 구현부.  
    Publisher가 Subscriber에게 이 오브젝트를 전달한다.
    

### Reactive Streams의 흐름

![pubsubandbackpressure](https://jongmin92.github.io/images/post/2019-11-05/reactive-streams.png)  
이미지 출처 : [https://jongmin92.github.io/%5D](https://jongmin92.github.io/%5D)

1.  subscriber의 구독 시작 (pub.subscribe(sub))
2.  onSubscribe를 통해 구독 시작
4.  Subscriber가 publisher로 Subscription을 통해 request, cancel method 전달
5.  Publisher가 Subscription을 통해 전달 속도 조절하며 요청 전달, 완료 및 에러 여부 전달

[reactive-streams GITHUB](https://github.com/reactive-streams/reactive-streams-jvm/tree/v1.0.3) 참고

```java
public static void main(String[] args) {
    //publisher - 내가 데이터 100만개 줄게!
    //subscriber - 나는 처리 못해 하나당 1초걸려
    //이런 경우 backpressure로 조절한다. -> 버퍼를 일정하게 유지하여 더욱 안정적이다.
    Iterable<Integer> itr = Arrays.asList(1,2,3,4,5);
    Publisher p = new Publisher() {
        @Override
        public void subscribe(Subscriber subscriber) {
            subscriber.onSubscribe(new Flow.Subscription() {
                //subscriber의 부탁이 쓰여있는 역할, backpressure(역압, 처리량 등을 조절하도록 하는 메서드들이 있다)

                Iterator<Integer> it = itr.iterator();
                @Override
                public void request(long n) {
                    while(n-- > 0){
                        if (it.hasNext()) {
                            subscriber.onNext(it.next());
                        }else{
                            subscriber.onComplete();
                            break;
                        }
                    }
                }
                @Override
                public void cancel() {

                }
            });
        }
    };
    Subscriber<Integer> s = new Subscriber<Integer>() {
        Flow.Subscription subscription;
        @Override
        public void onSubscribe(Flow.Subscription subscription) {
            //subscriber의 부탁이 들어있는 subscription을 바탕으로 pub에게 알림  부탁하는 메서드
            System.out.println("onSubscribe");
            this.subscription = subscription;
            subscription.request(1);
        }

        @Override
        public void onNext(Integer item) {
            //다음걸 줬다는 알림 역할
            System.out.println("onNext "+item);
            this.subscription.request(1);
        }

        @Override
        public void onError(Throwable throwable) {
            //Exception 발생 대신 Object 전달 역할 (try catch 필요없음)
            System.out.println("onError");
        }

        @Override
        public void onComplete() {
            //더이상 줄 데이터 없다는 알림
            System.out.println("onComplete");
        }
    };

    p.subscribe(s);
}
```

# Reactive Streams - Operator

## Publisher - Subscriber 의 기본 구조
````java
public class  PubSub {
    Publisher<Integer> pub = new Publisher<Integer>() {
        @Override
        public void subscribe(Subscriber<? super Integer> sub) {
            sub.onSubscribe(new Subscription() {
                @Override
                public void request(long l) {

                }

                @Override
                public void cancel() {

                }
            });
        }
    };
    Subscriber<Integer> sub = new Subscriber<Integer>() {
        @Override
        public void onSubscribe(Subscription subscription) {

        }

        @Override
        public void onNext(Integer i) {

        }

        @Override
        public void onError(Throwable t) {

        }

        @Override
        public void onComplete() {

        }
    };
}

````

## Operator
mapping, filter, reducer 등 Stream Data 가공하는 작업 진행

1. Map : Data1 -> function -> Data2

````java
public class PubSub {

    public static void main(String[] args) {
        Publisher<Integer> pub = iterPub(Stream.iterate(1, a -> a + 1).limit(10).collect(Collectors.toList()));
        Publisher<Integer> mapPub = mapPub(pub, s -> s * 10);
        Publisher<Integer> map2Pub = mapPub(mapPub, s -> -s);
        map2Pub.subscribe(logSub());
    }

    private static Publisher<Integer> mapPub(Publisher<Integer> pub, Function<Integer, Integer> f) {
        return new Publisher<Integer>() {
            //map을 이용한 operator 기능 구현
            @Override
            public void subscribe(Subscriber<? super Integer> sub) {
                pub.subscribe(new Subscriber<Integer>() {
                    @Override
                    public void onSubscribe(Subscription s) {
                        sub.onSubscribe(s);
                    }

                    @Override
                    public void onNext(Integer i) {
                        sub.onNext(f.apply(i));
                    }

                    @Override
                    public void onError(Throwable t) {
                        sub.onError(t);
                    }

                    @Override
                    public void onComplete() {
                        sub.onComplete();
                    }
                });
            }
        };
    }

    private static Subscriber<Integer> logSub() {
        return new Subscriber<Integer>() {
            @Override
            public void onSubscribe(Subscription s) {
                log.debug("onSubscribe:");
                s.request(Long.MAX_VALUE);
            }

            @Override
            public void onNext(Integer i) {
                log.debug("onNext:{}", i);
            }

            @Override
            public void onError(Throwable t) {
                log.debug("onError:{}", t);
            }

            @Override
            public void onComplete() {
                log.debug("onComplete");
            }
        };
    }

    private static Publisher<Integer> iterPub(final List<Integer> iter) {
        return new Publisher<Integer>() {
            @Override
            public void subscribe(Subscriber<? super Integer> sub) {
                sub.onSubscribe(new Subscription() {
                    @Override
                    public void request(long n) {
                        try {
                            iter.forEach(s -> sub.onNext(s));
                            sub.onComplete();
                        } catch (Throwable t) {
                            sub.onError(t);
                        }
                    }

                    @Override
                    public void cancel() {

                    }
                });
            }
        };
    }
}

````

2. sumPub - sumPub을 통해 값을 더해서 lobSub로 로그 출력

````java
public class PubSub {

    public static void main(String[] args) {
        Publisher<Integer> pub = iterPub(Stream.iterate(1, a -> a + 1).limit(10).collect(Collectors.toList()));
        Publisher<Integer> sumPub = sumPub(pub);
        sumPub.subscribe(logSub());
    }

    private static Publisher<Integer> sumPub(Publisher<Integer> pub) {
        return new Publisher<Integer>() {
            @Override
            public void subscribe(Subscriber<? super Integer> sub) {
                pub.subscribe(new DelegateSub(sub){
                    int sum = 0;

                    @Override
                    public void onNext(Integer i) {
                        sum+=i;
                    }

                    @Override
                    public void onComplete() {
                        sub.onNext(sum);
                        sub.onComplete();
                    }
                });
            }
        };
    }

    private static Subscriber<Integer> logSub() {
        return new Subscriber<Integer>() {
            @Override
            public void onSubscribe(Subscription s) {
                log.debug("onSubscribe:");
                s.request(Long.MAX_VALUE);
            }

            @Override
            public void onNext(Integer i) {
                log.debug("onNext:{}", i);
            }

            @Override
            public void onError(Throwable t) {
                log.debug("onError:{}", t);
            }

            @Override
            public void onComplete() {
                log.debug("onComplete");
            }
        };
    }
}
````

## Schedulers

액션을 별도의 스레드에서 작동시키고, 메인스레드에서 작동하도록 구현해보자.

1. SubscribeOn
![SubscribeOnImage](https://projectreactor.io/docs/core/release/api/reactor/core/publisher/doc-files/marbles/subscribeOnForFlux.svg)
[출처: projectreactor.io]
````java
Publisher<Integer> subOnPub = sub -> {
    ExecutorService es = Executors.newSingleThreadExecutor();
    es.execute(()->pub.subscribe(sub));
    //pub.subscribe(sub);
};
````

2. PublishOn
![PublishOnImage](https://projectreactor.io/docs/core/release/api/reactor/core/publisher/doc-files/marbles/publishOnForFlux.svg)
[출처: projectreactor.io]

````java
Publisher<Integer> pubOnPub = sub -> {
    pub.subscribe(new Subscriber<Integer>() {
        ExecutorService es = Executors.newSingleThreadExecutor();

        @Override
        public void onSubscribe(Subscription s) {
            sub.onSubscribe(s);
        }

        @Override
        public void onNext(Integer integer) {
            //반드시 단일 Thread 내에서 onNext()를 호출하도록 되어있다.
            es.execute(()->sub.onNext(integer));
        }

        @Override
        public void onError(Throwable t) {
            es.execute(()->sub.onError(t));
        }

        @Override
        public void onComplete() {
            es.execute(()->sub.onComplete());
        }
    });
};
````
