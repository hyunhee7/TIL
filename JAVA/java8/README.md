# java8

# Lambda
- 메서드를 하나의 '식'으로 표현한 것, '익명함수'라고도 함.
- 클래스, 객체 생성해야만 메서드 호출할 수 있지만, 람다의 경우 이 모든 과정 없이 오직 람다식 자체로 역할이 가능. 
## 람다식 작성하기
### 기존 방식
1회용 클래스, 객체를 생성하여 만든다. 
````java
MyFunction f = new MyFinction() {
    public int max(int a, int b) {
        return a > b ? a : b;
    }
};
int big = f.max(5, 3); //익명 객체의 메서드를 호출
````

### 람다 활용 방식
람다식을 다루기 위한 인터페이스를 **'함수형 인터페이스'** 라고 칭한다.

함수형 인터페이스에는 **오직 하나의 추상 메서드만 정의**해야 람다식과 인터페이스의 메서드가 1:1로 연결 가능.
     
````java
@FunctionalInterface
interface MyFunction {  //함수형 인터페이스 MyFunction 정의
    public abstract int max(int a, int b);
}
````
````java
MyFunction f = (int a, int b) -> a > b ? a : b; //익명 객체를 람다식으로 대체
int big = f.max(5,3); //익명 객체의 메서드를 호
````

자주 쓰는 예제를 하나 더 보자.
### 기존
````java
List<String> list = Arrays.asList("abc", "aaa", "bbb", "ddd", "aaa");

Collections.sort(list, new Comparator<String>() {
    public int compare(String s1, String s2) {
        return s2.compareTo(s1);
    }
});
````

### 람다 활용
````java
List<String> list = Arrays.asList("abc", "aaa", "bbb", "ddd", "aaa");
Collections.sort(list, (s1, s2) -> s2.compareTo(s1));
````
## java.util.function 패키지
### 컬렉션 프레임웍과 함수형 인터페이스
(그냥 코드로 보는게 이해가 빠르더라.)

````java
//list의 모든 요소 출력
list.forEach(i->System.out.print(i+","));

//list에서 2 또는 3 배수 제거
list.removeIf(x-> x%==0 || x%3==0);

//list에서 각 요소에 10을 곱한다
list.replaceAll(i->i*10);

Map<String, String> map = new HashMap<>();
map.put("1", "1");
map.put("2", "2");
map.put("3", "3");
map.put("4", "4");

//map의 모든 요소를 {k,v} 형식으로 출력한다.
map.forEach((k, v)->System.out.print("{"+k+","+v+"},"));
````

## Stream
List는 Collections.sort()를 사용하고, 배열은 Arrays.sort()를 사용해야 하는 불편한 문제를 해결하기 위해 만든 것이 Stream 이다.

데이터 소스를 추상화하고, 데이터를 다루는데 자주 사용되는 메서드들을 정의해 놓았다.

````java
String[] strArr = {"aaa", "ddd", "ccc"};
List<String> strList = Arrays.asList(strArr);
````
위 코드를 기반으로 하는 스트림은 아래와 같다.
````java
Stream<String> strStream1 = strList.stream();
Stream<String> strStream2 = Arrays.stream(strArr);
````
위 두 개의 스트림으로 데이터를 읽 정렬하고 출력하는 방법 (정렬되는 것은 아님) 
````java
//스트림을 이용한 정렬 및 출력
strStream1.sorted().forEach(System.out::println);
strStream1.sorted().forEach(System.out::println);

//기존의 방법이라면..
Arrays.sort(strArr);
Collections.sort(strList);

for(String str : strArr)
    System.out.println(str);

for(String str : strList)
    System.out.println(str);
````
정렬과 출력이 완전 동일함을 알 수 있다! 또, 간결하고 이해가 쉬움.

## 스트림의 특징
### 스트림은 데이터 소스를 변경하지 않는다.
읽기만 할 뿐 변경하지 않는다. 정렬된 결과를 컬렉션이나 배열에 담아야만 반환 가능!
### 스트림은 일회용이다.
Iterator처럼 한번 사용하면 닫혀서 다시 사용이 불가능하다.
### 스트림은 작업을 내부 반복으로 처리한다.
forEach 메서드
### 스트림의 연산
다양한 연산 이용해 간단하게 작업 처리 가능

## 스트림의 연산
### 배열
````java
Stream<String> strStream = Stream.of("a","b","c");
Stream<String> strStream = Stream.of(new String[] {"a","b","c"});
Stream<String> strStream = Stream.of(new String[] {"a","b","c"}, 0, 3); // int startInclusive, int endExclusive
````
### 특정 범위의 정수
지정된 범위의 연속된 정수를 스트림으로 생성
````java
IntStream.range(int begin, int end)
IntStream.rangeClosed(int begin, int end)
````
### 람다식 - iterator(), generate()
람다식에 의해 계산되는 값들을 요소로 하는 무한 스트림을 생성한다.

- Iterator
````java
Stream<Integer> evenStream = Stream.iterate(0, n->n+2); //0, 2, 4, 6, ...
````
- generate()

무한 스트림 생성해 반환하나, 이전 결과를 갖고 다음 요소를 계산하지 않는다.
````java
Stream<Integer> randomStream = Stream.generate(Math::random); //0, 2, 4, 6, ...
````
이때, 반환값을 IntStream, DoubleStream 같은 기본형 스트림 타입의 참조변수로 다룰 수 없음. 이건 MapToInt() 사용하면 됨.

### 빈 스트림
스트림의 연산을 수행한 결과가 하나도 없을 때 null 보다는 빈 스트림 반환이 좋다.
````java
Stream emptyStream = Stream.empty();
long count = emptyStream.count(); // 0
````

### 두 스트림의 연결
스트림끼리 연결이 가능하다
````java
Stream<String> strs1 = Stream.of(str1);
Stream<String> strs2 = Stream.of(str2);
Stream<String> strs3 = Stream.concat(strs1, strs2);
````
## 스트림의 중간 연산
### 자르기 - skip(), limit()
````java
IntStream intStream = IntSream.rangeClosed(1,10); //1-10을 갖는 스트림 생성
intStream.skip(3).limit(5).forEach(System.out::print); //4,5,6,7,8
````
### 요소 걸러내기 - filter(), distinct()
filter - 조건에 맞는 요소만 넣음
````java
IntStream intStream = IntSream.rangeClosed(1,10);
intStream.filter(i -> i%2==0).forEach(System.out::print);
````
distinct - 스트림의 중복 요소들을 제거
````java
IntStream intStream = IntSream.of(1,2,2,3,4,4,5,5,5,6,6,6,6,6,6);
intStream.distinct().forEach(System.out::print); // 123456
````
### 정렬 - sorted()
````java
Steam<String> strStream = Stream.of("dd", "aaa", "CC", "cc", "b");
strStream.sorted().forEach(System.out::print); // CCaabccdd
strStream.sorted((s1,s2)->s1.compateTo(s2));
strStream.sorted(Comparator.reverseOrder());
strStream.sorted(Comparator.<String>naturalOrder().reverse());
````
학생 스트림을 반별, 성적순, 이름순으로 정렬하고 출력
````java
studentStream.sorted(Comparator.comparing(Student::getBan)
                                .thenComparing(Student::getTotalScore)
                                .thenComparing(Student::getName)
                                .forEach(System.out::println));
````
### 변환 - map()
원하는 필드만 뽑아내거나 특정 형태로 변환해야할 때 사용
````java
Stream<File> fileStream = Stream.of(new File("ex1.java"), new File("ex1"), new File("ex2.java"), new File("ex1.bak"), new File("ex1.txt"));
Stream<String> filenameStream = fileStream.map(File::getName)
                                          .filter(s -> s.indexOf('.')!=-1) //확장자가 없으면 제외
                                          .map(String::toUpperCase)        
                                          .distinct()                      //중복제거
                                          .forEach(System.out::print);     //JAVABAKTXT
````

### 조회 - peek()
연산과 연산 사이에 확인할 때 사용
````java
fileStream.map(File::getName)
          .filter(s -> s.indexOf('.')!=-1)
          .peek(s->System.out.printf("filename=%s%n", s)) //파일명을 출력한다.
````

### mapToInt(), mapToLong(), mapToDouble()
````java
IntStream studentScoreStream = studentStream.mapToInt(Student::getTotalScore);
int allTotalScore = studentScoreStream.sum(); //스트림의 모든 요소 총합 - 기본스트림에서 제공하는 메서드
````

## Optional<T>, OptionalInt
최종 연산 결과 타입으로 자주 씀.


## 스트림의 최종 연산
### * forEach()
### * 조건 검사 
allMatch(), anyMatch(), noneMatch(), findFirst(), findAny()

boolean으로 리턴한다.

### * 통계 
count(), sum(), average(), max(), min()'

### * collect()
스트림의 요소를 수집하는 최종 연산.
* collect() - 스트림의 최종 연산, 매개변수로 컬렉터를 필요로 함.
* Collector - 인터페이스, 컬렉터는 이 인터페이스를 구현해야 한다.
* Collectors - 클래스, static메서드로 미리 작성된 컬렉터를 제공해야한다.

````java
List<String> names = stuStream.map(Student::getName).collect(Collectors.toList());
ArrayList<String> list = names.stream().collect(Collectors.toCollection(ArrayList::new));
````
### * 스트림을 컬렉션과 배열로 변환
toList(), toSet(), toMap(), to Collection(), toArray()
### * 통계 
counting(), summingInt(), averagingInt(), maxBy(), minBy()
### * 리듀싱 
reducing()
### * 문자열 결합 
joining()


## 스트림의 중간 연산
### * 자르기 - skip(), limit()
````java
IntStream intStream = IntSream.rangeClosed(1,10); //1-10을 갖는 스트림 생성
intStream.skip(3).limit(5).forEach(System.out::print); //4,5,6,7,8
````
### * 요소 걸러내기 - filter(), distinct()
filter - 조건에 맞는 요소만 넣음
````java
IntStream intStream = IntSream.rangeClosed(1,10);
intStream.filter(i -> i%2==0).forEach(System.out::print);
````
distinct - 스트림의 중복 요소들을 제거
````java
IntStream intStream = IntSream.of(1,2,2,3,4,4,5,5,5,6,6,6,6,6,6);
intStream.distinct().forEach(System.out::print); // 123456
````
### * 정렬 - sorted()
````java
Steam<String> strStream = Stream.of("dd", "aaa", "CC", "cc", "b");
strStream.sorted().forEach(System.out::print); // CCaabccdd
strStream.sorted((s1,s2)->s1.compateTo(s2));
strStream.sorted(Comparator.reverseOrder());
strStream.sorted(Comparator.<String>naturalOrder().reverse());
````
학생 스트림을 반별, 성적순, 이름순으로 정렬하고 출력
````java
studentStream.sorted(Comparator.comparing(Student::getBan)
                                .thenComparing(Student::getTotalScore)
                                .thenComparing(Student::getName)
                                .forEach(System.out::println));
````
### * 변환 - map()
원하는 필드만 뽑아내거나 특정 형태로 변환해야할 때 사용

[연습코드](https://github.com/hyunhee7/TIL/blob/master/Algorithm/Algorithm_JAVA/src/java8/stream/StreamCollect.java)

### * 그룹화와 분할 - groupingBy(), partitioningBy()

* partitioningBy()에 의한 분류
    
    학생들을 성별로 나누어 List에 담는다.

    ````java
    //1. 기본 분할
    Map<Boolean, List<Student>> stuBySex = stuStream.collect(partitioningBy(Student::isMale));
    //남학생 목록
    List<Student> maleStudent = stuBySex.get(true);
    //여학생 목록
    List<Student> femaleStudent = stuBySex.get(false);
  
    //2. 기본 분할 + 통계 정보
    Map<Boolean, Long> stuNumBySex = stuStream.collect(partitioningBy(Student::isMale, counting()));
    System.out.println("남학생 수: "+stuNumBySex.get(true));
    System.out.println("여학생 수: "+stuNumBySex.get(false));
  
    //3. 총점은 어떻게 구할까
    Map<Boolean, Optional<Student>> topScoreBySex = stuStream.collect(
          partitioningBy(Student::isMale, maxBy(comparingInt(Student::getScore))
      )
    );
    System.out.println("남학생 1등:"+topScoreBySex.get(true)); // 남학생 1등 :Optional[[김, 남, 1, 1, 300]]
    System.out.println("여학생 1등:"+topScoreBySex.get(true)); // 여학생 1등 :Optional[[김, 남, 1, 1, 390]]
    ````
  
* groupingBy()

    그룹을 지어 Map에 저장. 통계낼 때 많이 사용하는 듯 하다

    [groupping 예제](https://github.com/hyunhee7/TIL/blob/master/Algorithm/Algorithm_JAVA/src/java8/stream/StreamGrouppingBy.java)
    


