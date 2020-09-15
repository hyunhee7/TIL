# java8

## Lambda
- 메서드를 하나의 '식'으로 표현한 것, '익명함수'라고도 함.
- 클래스, 객체 생성해야만 메서드 호출할 수 있지만, 람다의 경우 이 모든 과정 없이 오직 람다식 자체로 역할이 가능. 
### 람다식 작성하기
#### 기존 방식
1회용 클래스, 객체를 생성하여 만든다. 
````java
MyFunction f = new MyFinction() {
    public int max(int a, int b) {
        return a > b ? a : b;
    }
};
int big = f.max(5, 3); //익명 객체의 메서드를 호출
````

#### 람다 활용 방식
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
#### 기존
````java
List<String> list = Arrays.asList("abc", "aaa", "bbb", "ddd", "aaa");

Collections.sort(list, new Comparator<String>() {
    public int compare(String s1, String s2) {
        return s2.compareTo(s1);
    }
});
````

#### 람다 활용
````java
List<String> list = Arrays.asList("abc", "aaa", "bbb", "ddd", "aaa");
Collections.sort(list, (s1, s2) -> s2.compareTo(s1));
````
### java.util.function 패키지
#### 컬렉션 프레임웍과 함수형 인터페이스
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

### Function의 합성과 Predicate의 결합
