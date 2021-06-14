# 숫자 야구 게임 - 단위테스트

## 단위 테스트란?

### Main Method의 용도
* 프로그램의 시작
* 구현된 프로그램을 테스트

### Main Method 테스트의 문제점
* Production Code와 Test 코드가 한 공간에 공존
* Test 코드가 실 서비스에 같이 배포
* main method 하나에서 여러 개의 기능 테스트 진행. = 복잡도 증가
* method 이름으로 어떤 테스트를 하는지 알 수 없음. = 가독성 낮음
* 테스트 결과를 수동으로 확인. = 생산성 감소

### JUnit
* main 메서드를 활용해 테스트할 때 발생하는 문제점을 해결하기 위해 나타난 도구

#### JUnit 5.x 버전
* Annotation을 활용해 테스트 코드 구현
    * @Test
    * @BeforeEach
    * @AfterEach
    * Assertions 클래스의 static assert method를 활용해 테스트 결과 검증
    
#### JUnit 4.x 버전


## 의식적인 연습과 학습 테스트
* 테스트를 하기 쉬운 코드와 테스트를 하기 어려운 코드를 보는 눈
* 테스트 하기 어려운 코드를 테스트 하기 쉬운 코드로 설계하는 센스(감)

### 의식적인 연습의 7가지 원칙
* 효과적 훈련 기법이 설계되어있는 기법 연마
* 컴포트존을 벗어난 지점에서 진행, 현재 내 능력에서 살짝 넘어가는 작업 지속적 시도
* 명확하고 구체적 목표
* 피드백과 그에 따른 행동 변경

## 단위테스트 != TDD

### 학습테스트
새로운 라이브러리 등을 익힐 때, 단위 테스트 기반으로 익힌다. = 학습속도가 빠르다.

````
public class StringTest {
    @Test
    public void split() {
        String[] values = "1".split(",");
        assertThat(values).contains("1");
        values = "1,2".split(",");
        assertThat(values).containsExactly("1","2");
    }

    @Test
    public void substring() {
        String input = "(1,2)";
        String result = input.substring(1, input.length()-1);
        assertThat(result).isEaqualsTo("1,2");
    }
}
````

## 목표
1. 단위테스트 방법을 익힌다.
2. xUnit 사용법을 익힌다.
3. 사용하는 API에 대한 학습효과를 얻는다.