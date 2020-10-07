# DDD (도메인 주도 설계)
최범균의 DDD Start 를 읽은 것을 바탕으로 정리한 내용입니다.

# 1. 도메인 모델 시작
도메인 모델을 사용하면 여러 관계자들이 동일한 모습으로 도메인을 이해하고 공유하는데 도움이 된다.

도메인 기능, 주요 데이터 구성 파악이 필요한데, 기능과 데이터를 함께 보여주는 객체 모델

## 엔티티
* 식별자를 갖는다. (Ex. 주문 도메인의 주문번호)
* 식별자는 바뀌지 않는다.
* 특정 규칙, UUID, 일련번호 등 사용

## 벨류
* 클래스로 만들어 의미 전달이 가능해진다.
* 코드 가독성이 높아진다.
* 밸류 타입은 불변으로 만든다. (참조투명성)
    ````java
    Money price = new Money(1000);
    OrderLine line = new OrderLine(product, price, 2); //[price=1000]
    price.setValue(2000); //[price=2000]
    ````
    setValue()가 가능하면, line의 price와  price객체의 값이 달라진다.
    
## 도메인 모델에 set 메서드 넣지 않기
* get/set메서드를 습관적으로 넣는 것은 바람직하지 않다.
    ````java
    Order order = new Order();
    order.setOrderLine(lines);
    order.setState(OrderState.PREPARING); // 주문자(Orderer)를 설정하지 않은 상태에서 주문완료처리
    ````
    이러한 경우를 막기 위해서 생성자를 사용한다. 그러면, 필요값 모두 받고 내부에서 데이터 올바른지 검사까지 가능
    ````java
    public class Order{
      public Order(Orderer orderer, ShippingInfo shippingInfo, OrderState state){
          setOrderer(orderer);
          ...
      }
      private void setOrderer(Orderer orderer) {
          if(orderer == null) throw new IllegalArgumentException("no orderer");
          this.orderer = orderer;
      }      
    }
    ````
    내부에서 데이터를 변경할 목적으로 사용된다. private이기 때문에 외부에서 데이터를 변경할 목적으로 set메서드 사용 불가.
    
## 도메인 용어
* 도메인에서 사용하는 용어를 코드에 최대한 반영해주면 가독성 높아짐. 

  ----> 코드 분석 및 이해 시간 절약, 도메인 규칙을 코드로 작성해서 버그도 줄어듦.
* 상태(state, status), 종류(kind, type)등 적절한 것을 선택할 줄 아는 센스 필요

# 2. 아키텍처 개요
## 계층 구조 아키텍처
* 아키텍처 구성 - 표현, 응용, 도메인, 인프라스트럭처
* 표현 --> 응용 --> 도메인 --> 인프라스트럭처 : 상위 계층에서 하위 계층으로 의존 존재
* 표현, 응용, 도메인 계층이 상세한 구현 기술을 다루는 인프라스트럭처 계층에 종속된다.
* 인프라스트럭처 의존 시, '테스트 어려움'과 '기능 확장 어려움'의 문제 발생

## DIP(Dependency Inversion Principle)
저수준 모듈이 고수준 모듈에 의존하도록 바꾼다.
위와 같은 문제를 해결해준다. 
* 가격 할인 계산(고) = 고객정보 구하기 + 룰을 이용한 할인금액 구하기 (저)
* 저수준 모듈에 의존하는 고수준 모듈
* **'테스트 어려움'과 '기능 확장 어려움'** 발생

### 어떻게?
추상화한 인터페이스 활용, 차이를 한번 보자

#### 문제가 있는 코드
````java
public class CalculateDiscountService{
    private DroolsRuleEngine ruleEngine;
    public CalculateDiscountService(){
        ruleEngine = new DroolsRuleEngine();
    }
    
    public Money calculateDiscount(List<OrderLine> orderLines, String customId) {
        Customer customer = findCustomer(customerId);
    
        MutableMoney money = new MutableMoney(0); //Drools에 특화된 코드
        List<?> facts = Arrays.asList(customer, money); //룰에 필요한 데이터
        facts.addAll(orderLines); //룰에 필요한 데이터
        ruleEngine.evaluate("discountCalculation", facts); //discountCalculation - 세션이름
        return money.toImmutableMoney();
    }
}
````
#### DIP를 활용한 코드
````java
public interface RuleDiscounter {
    public Money applyRules(Customer customer, List<OrderLine> orderLines);
}
````
````java
public class CalculateDiscountService {
    private RuleDiscounter ruleDiscounter;
    
    public CalculateDiscountService(RuleDiscounter ruleDiscounter) {
        this.ruleDiscounter = ruleDiscounter;
    }
    
    public Money calculateDiscount(List<OrderLine> orderLines, String customerId) {
        Customer customer = findCustomer(customerId);
        return ruleDiscounter.applyRules(customer, orderLines); //추상화 한 메서드에 넣어버림
    }
    ...
}
````
````java
public class DroolsRuleDiscounter implements RuleDiscounter {
    private KieContainer kContainer;
    public DroolsRuleDiscounter(){
        KieService ks = KieServices.Factory.get();
        kContainer = ks.getKieClasspathContainer();
    }   
    @Override
    public Money applyRule(Customer customer, List<OrderLine> orderLines) {
        KieSession kSession = kContainer.newKieSession("discountSession");
        try{
            ...
            kSession.fireAllrules();
        } finally {
            kSession.dispose();
        }
        return money.toImmutableMoney();
    }
}
````
저수준 모듈(DroolsRuleDiscounter)이 고수준 모듈(CalculateDiscountService, RuleDiscounter)에 의존하는 형태로 바뀌었다!
-> 방식의 교체가 어려운 문제, 테스트 어려운 문제를 해소했다!!

### DIP 주의사항
* 단순한 인터페이스와 구현 클래스 분리 아님
* 잘못된 예 : 도메인 - CalculateDiscountService, 인프라 - RuleEngine(인터페이스), DroolsRuleEngine
* 올바른 예 : 도메인 - CalculateDiscountService, RuleDiscount(인터페이스), 인프라 - DroolsRuleEngine



## 도메인 영역의 주요 구성요소
### 엔티티와 밸류
* 도메인 모델, DB모델의 엔티티 차이점
    1. 도메인 모델 엔티티 
       * 데이터 + 도메인 기능 제공 (ex. 주문 데이터 + 배송지 변경 기능)
       * 두 개 이상의 데이터가 한 개념일 때, 밸류 타입 이용 가능
            ````java
            public class Orderer{
                private String name;
                private String email;
                 ..
            }
            ````
       * 밸류 타입 데이터 변경 시, 새로운 객체로 교체
    2. DB모델의 엔티티
        * 밸류를 표현하기 힘들다.
    
### 애그리거트
* (엔티티 + 밸류)객체를 관련있는 것끼리 묶은 군집
* 애그리거트 내부 구현 숨겨 애그리거트 단위 캡슐화 가능
#### 애그리거트 루트
군집 속한 객체들 관리, 속한 엔티티와 밸류 객체 이용하 애그리거트가 구현해야할 기능을 제공


### 리포지터리
물리적인 저장소에 도메인 객체 보관 위한 도메인 모델
* 가장 기본 메서드 = 저장, 조회 (+삭제, 카운팅 등)
* 주문 취소 기능
    ````java
    public class CancelOrderService {  
      private OrderRepository orderRepository;
      public void cancel(OrderNumber number) {
          Order order = orderRepository.findByNumber(number);
          if (order==null) throw new NoOrderException(number);
          order.cancel();
      }
      ... 
    }
    ````
    도메인 모델 관점에서 OrderRepository = 고수준 모델 (기능을 추상화했기 때문)
    


