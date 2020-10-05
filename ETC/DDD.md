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

    
  