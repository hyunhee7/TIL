# JAVA 관련 ISSUE 기록
학습하며 자주 헷갈리는 부분, 공부가 필요한 부분을 기록하는 공간입니다.

# Comparable, Comparator 이용한 객체 정렬
사용자 정의에 의해 정렬할 때 이용

	EX1. x좌표는 증가하는 순, x좌표가 같으면 y좌표가 감소하는 순
    EX2. 국어 점수 증가 순, 같을 경우 수학 점수 감소 순

그렇다면, 객체의 정렬 기준을 명시하는 방법?

	1. Comparable interface
		- 정렬할 객체에 Comparable interface를 implement 후 compareTo() 메소드 오버라이드
		- compareTo() 메소드는 현재 객체가 파라미터로 넘어온 객체보다 작으면 음수 return, 같으면 0 return, 크면 양수 return 하도록 작성.
		- Collections.sort(list) 
		
	2. Comparator interface
		- Collections.sort() 메소드의 두 번째 인자 Comparator interface를 활용
		- Comparator interface를 implements 후 compare() 메소드를 오버라이드한 myComparator class 작성
		- compareTo() 메소드는 첫 번째 파라미터로 넘어온 객체가 두 번째 파라미터로 넘어온 객체보다 작으면 음수 리턴, 같으면 0 리턴, 크면 양수 리턴

## 예제
## Comparable
```java
class Point implements Comparable<Point> {
	int x, y;
    
    @Override
    public int compareTo(Point p){
    	if(this.x > p.x){
        	return 1;
        }
        else if(this.x == p.x){
        	if(this.y > p.y) {
            	return 1;
            }
        }
        return -1;
    }
}

//Main
List<Point> pointList = new ArrayList<>();
pointList.add(new Point(x,y));
Collections.sort(pointList);
```

## Comparator
```java
class MyComparator implements Comparator<Point>{
	@Override
    public int compare(Point p1, Point p2){
    	if (p1.x > p2.x){
        	return 1;
        }
        else if(p1.x == p2.x){
        	if (p1.y > p2.y){
            	return 1;
            }
        }
        return -1;
    }
}

//Main
List<Point> pointList = new ArrayList<>();
MyComparator myComparator = new MyComparator();
Collections.sort(pointList, myComparator);
```

# String, StringBuilder, StringBuffer의 차이
## String
* 새로운 값을 할당할 때마다 새로운 클래스에 대한 객체가 생성
* String 값은 바꿀 수 없다.
	* String 저장 형태 : private final char[]
	* private : 외부에서 접근 불가
	* final : 초기값 변경 불가
* String + String + String ...
	* 각각의 String 주소값이 Stack에 쌓임
	* Garbage Collector 호출 전까지 String 객체들은 Heap에 쌓여 메모리에 치명적
	* String 직접 더하는 것보다 StringBuilder, StringBuffer 이용이 더 좋다.

## StringBuilder, StringBuffer
* 메모리에 append하는 방식
* 클래스에 대한 객체를 직접 생성하지 않는다.
* StringBuilder
	* 변경 가능한 문자열
	* 비동기 처리
* StringBuffer
	* 변경 가능한 문자열
	* 동기 처리
	* multiple thread 환경에서 안전한 클래스(thread safe)
	

# IO
## 스트림
연속적인 데이터의 흐름. 단방향 통신만 가능.

입력과 출력 동시 수행을 위해서는 입력, 출력 2개의 스트림이 필요.

큐(FIFO)의 구조.

## 바이트기반 스트림 - InputSream, OutputStream
스트림은 1바이트단위로 데이터를 전송하며, 입출력 대상에 따라 스트림을 선택해 사용한다.

### 파일
* FileInputStream
* FileOutputStream

### 메모리
* ByteArrayInputStream
* ByteArrayOutputStream

### 프로세스
* PipedInputStream
* PipedOutputStream

### 오디오장치
* AudioInputStream
* AudioOutputStream

## 보조 스트림
실제 데이터를 주고받지 않아 데이터를 입출력할 수 없지만 기능향상, 새로운 기능 추가가 가능하다.

````java
//1. 기반 스트림 생성
FileInputStream fis = new FileInputStream("test.txt");
//2. 기반 스트림 이용해 보조 스트림 생성
BufferedInputStream bis = new BufferedInputStream(fis);
//3. 보조스트림 bis로 부터 데이터를 읽는다.
bis.read();
````

## 문자기반 스트림
문자열 처리의 경우 Java에서 2byte 이기 때문에 문자 기반의 스트림 사용해야 한다.

바이트 기반 스트림을
* InputStream -> Reader
* OutputStream -> Writer

로 바꾸면 문자 기반의 스트림이 된다.