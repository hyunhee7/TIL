# ORM

## JPA를 사용해야하는 이유
### 생산성
1. 저장 - jpa.persist(member)
2. 조회 - Member member = jpa.find(memberId)
3. 수정 - member.setName("변경할 이름")
4. 삭제 - jpa.remove(member)

### 유지보수
SQL에 칼럼을 추가할 번거로움 없이, 객체 필드만 추가하면 된다.

### 상속
* jpa.persist(album) 을 수행
* INSERT INTO ITEM .. 과 INSERT INTO ALBUM 을 수행

### 신뢰할 수 있는 엔티티
````java
class MemberService{
    public void process(){
        Member member = memberDAO.find(memberId);
        member.getTeam();
        member.getOrder().getDelivery(); //자유로운 객체 그래프 탐색
    }
}
```` 
### 객체끼리 비교하기
동일한 트랜잭션에서 조회한 엔티티는 동일성 보장

