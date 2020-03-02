# ITEM1.  생성자 대신 static 팩토리 메소드 고려하기
## 부제 : static 팩토리의 유연성

아래 정리는 백기선님의 강의를 참고하여 정리하였습니다.



## 장점 1: 이름을 가질 수 있습니다.
#### 이름 부여하기
적절한 이름을 가진 static 팩토리를 사용하여 가독성을 높일 수 있습니다.
```
public class Foo{
	String name;
    
    public Foo(String name){
    	this.name = name;
    }
    public static Foo withName(String name){
    	return new Foo(name);
    }
    public static void main(String[] args){
    	Foo foo1 = new Foo(name:"Hyunhee");
        //foo2의 경우, 가독성이 더 좋다.
        Foo foo2 = new Foo.withName("Hyunhee);
    }
}
```
#### 클래스 내 시그니처가 동일할 경우
똑같은 타입을 파라미터로 받는 생성자 두 개를 만들 수 없으므로 public static 팩토리 메소드를 사용하는 것이 유용하다.
```
public class Foo{
	String name;
    String address;
    
    public Foo(String name){
    	this.name = name;
    }
    public static Foo withAdress(String name){
    	Foo foo = new Foo();
        foo.address = address;
    	return foo;
    }
    public static Foo withName(String name){
    	return new Foo(name);
    }
    public static void main(String[] args){
    	//
    	Foo foo1 = new Foo(name:"Hyunhee");
        //foo2의 경우, 가독성이 더 좋다.
        Foo foo2 = new Foo.withName("Hyunhee);
    }
}
```

## 장점 2 : 반드시 새로운 객체를 만들 필요가 없습니다.
#### 객체 생성이 아닌 Boolean에 있는 상수를 리턴
```
public static Boolean valueOf(boolean b){
	return b? Boolean.TRUE : Boolean.FALSE;
}
```
#### 이미 있는 객체를 리턴
```
public class Foo{
	private static final Foo GOOD_MORNING = new Foo();
    public static Foo getFoo(){
		return GOOD_NIGHT;
    }
    public static void main(String[] args){
    	Foo foo = Foo.getFoo();
    }
}

```

## 장점 3 : 리턴 타입의 하위 타입 인스턴스 생성
리턴 타입은 인터페이스로 지정하고, 인터페이스의 구현체는 API로 노출 시키지 않습니다. 이로써 public으로 제공해야 할 API를 줄이고 개념의 난이도(Conceptual weight)를 줄입니다.
자바8부터 인터페이스에 public static 메소드를 추가할 수 있게 되었지만, private static 메소드는 자바 9부터 추가가 가능합니다.

#### private static 메서드가 필요한 상황?
private 메서드가 필요한 상황과 동일.
```
public calss plan{
    public static void doSomething(){
        //TODO 청소를 한다.

        //TODO 카페에 간다.

        //TODO 저녁을 먹는다.

        //TODO 잔다.
        doGame();
    }
    public static void doSomethingTomorrow{
    	//TODO 점심 먹는다
        
        //TODO 잔다.
        doGame();
    }
    
    //밖으로 노출될 필요 없는 메서드 (static은 static만 호출 가능)
    private static void doGame(){
    	//TODO 게임한다.
        //TODO 잔다.
    }
}

```
## 장점 4 : 리턴하는 객체의 클래스가 입력 매개변수에 따라 변화
Foo의 하위 타입이 있다면 꼭 Foo가 아닌 하위 타입을 리턴해도 됩니다.
```
public class Foo{
	public static Foo getFoo(boolean flag){
    	return flag ? new Foo() : new Barfoo();
    }
    public static void main(String[] args){
    	//flag에 따라 다른 객체를 리턴할 수 있다.
    	Foo foo = Foo.getFoo(false);
    }
    static class BarFoo extends Foo {
    }
}
```

예시로, EnumSet 클래스는 생성자 없이 public static 메소드, allOf(), of() 등을 제공합니다. 그 안에서 리턴하는 객체의 타입은 enum 타입의 개수에 따라 RegularEnumSet 또는 JumboEnumSet으로 달라집니다. (이러한 객체 타입은 감춰져 있어 그리 중요치 않음)

## 장점 5 : 리턴하는 객체의 클래스가 public static 팩토리 메소드를 작성할 시점에 반드시 존재하지 않아도 됨
메서드 생성 후, 나중에 Foo타입의 다른 클래스를 생성하여 사용이 가능.
JDBC getConnection 메서드를 사용하면 DB마다 다 다른 객체를 return(mysql, oracle 등등..)하는 것과 같은 느낌
```
public class Foo{
	public static Foo getFoo(boolean flag){
    	Foo foo= new Foo();
        // TODO 약속된 텍스트 파일에서 Foo의 구현체의 FQCN을 읽어온다
        // TODO FQCN에 해당하는 인스턴스 생성
        // TODO foo변수를 해당 인스턴스를 가리키도록 수정
        return foo;
    }

}
public class MyFoo extends Foo{
}
```

## 단점 1 : 프로그래머가 static 팩토리 메소드를 찾는게 어렵다.
생성자는 javadoc상단에 모아서 보여주지만, static 팩토리 메소드는 API 문서에서 특별히 다루지 않습니다.