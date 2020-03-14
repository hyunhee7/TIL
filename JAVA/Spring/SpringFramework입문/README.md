# 스프링프레임워크 입문

백기선님의 스프링프레임워크 입문 강의를 바탕으로 정리한 글입니다.

## IoC (Inversion of Controll)

### 일반적인 의존성에 대한 제어권
```java
class OwnerController{
	//new를 이용해 생성
	private OwnerReposibory repository = new OwnerRepository();
}
```
### 제어권을 프레임워크로 넘길 때
```java
class OwnerController{
	//누군가 생성자가 주겠지 라고 생각하고 선언
	private OwnerRepository repo;
    
    public OwnerController(OwnerRepository repo){
    	this.repo = repo;
    }
    
    //repo 사용
}

class OwnerControllerTest{
	@Test
    public void create(){
    	OwnerRepository repo= new OwnerRepository();
        OwnerController controller = new OwnerController(repo);
    }
}
```

## IoC 컨테이너
빈(bean)을 만들고 엮어주며 제공해준다.
```java
class OwnerController{
	//객체 생성은 IoC컨테이너가 해주기로 하고, 그냥 repo를 사용하면 된다.
	private OwnerRepository repo;
    
    public OwnerController(OwnerRepository repo){
    	this.repo = repo;
    }
    
    //repo 사용
}
```

* 위와 같은 코드가 동작하도록 해준다.
* OwnerController가 IoC 컨테이너 내부에 들어오면 IoC 컨테이너 내부에서 bean(객체)를 만든다.
* 연속적으로 OwnerRepository 객체도 생성
* 즉, 생성된 Bean들의 **의존성**을 **IoC 컨테이너가 관리**한다.

## Bean
스프링 IoC 컨테이너가 관리하는 객체
### Bean 등록법
ex. OwnerRepository는 Bean이고, Owner, Pet은 Bean이 아니다.

#### Component Scanning
	
* @Component
	* @Repository
	* @Service
	* @Controller


	ex. PetClinicApplication 내 @SpringBootApplicatio 의 Component-Scan
  	* Annotation은 기능이 없음.(주석과 같음, 단지 어디에 붙일 수 있느냐, 언제까지 그 주석 유지하냐)
  	* Component Scan annotation을 발견하면, 모든 package에 component라는 annotation이 붙어있는 클래스 찾아서 bean으로 등록.
  	* @Controller 도 열어보면 @Component로 등록되어 있음.
  	* Application 내에 등록해야 component 등록됨.



#### 직접 등록
단, Bean anno 메소드 정의할 때는 Configuration annotation 갖고 있는 클래스 안에서 정의해야함.

```java
@SpringBootApplication(proxyBeanMethods = false)
public class PetClinicApplication {

	public static void main(String[] args) {
		SpringApplication.run(PetClinicApplication.class, args);
	}

}
```
@SpringBootApplication 내부 @SpringBootConfiguration 내부 @Configuration 이 있는 것을 확인할 수 있다.

## 의존성 주입(Dependency Injection)

### @Autowired / @inject 를 어디에 붙일까?
* 생성자
* 필드
* Setter

	cf. autowired를 써주지 않아도 되는 경우(@autowired 생략 가능한 경우)
        조건1. 빈이 되는 클래스에 빈의 생성자가 오로지 하나
        조건2. 그 생성자의 매개변수 타입이 빈으로 등록되어 있는 경우
        
