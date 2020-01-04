
# SSO

## SSO란?
여러 서비스를 **로그인 한 번**으로 이용하도록 하는 기술
	- SP : Service Provider
	- IdP: Identity Provider, 인증 관련 부분만 모아서 구현해 놓은 것.

## SSO의 구성 요소

1. 사용자 통합 로그인
2. 인증 서버
3. 통합 에이전트 : 각 정보 시스템에 대한 정보 관리
4. LDAP(Lightweight Directory Access Protocol) : 네트워크 상의 자원을 식별하고 인가된 사용자만 접근하도록 하는 네트워크 디렉토리 서비스

## SSO의 기술 요소
- 인증 : PKI, 생체 인식, OTP
- 관리 : LDAP, 쿠키
- 암호화 통신 : SSL(Secure Socket Layer), IPSec(IP Security Protocol)

## SSO 동작 방식

    1. 사용자가 SP를 사용하려 한다.
    2. 사용자의 세션 정보가 SP에 남아있지 않아, SP는 사용자를 IdP로 redirect시킨다.
    3. 사용자의 세션 정보가 IdP에 남아있지 않아서, 사용자는 IdP에서 로그인 한다.
    4. 인증 완료되면, IdP는 사용자를 다시 SP로 redirect시키며, 동시에 사용자의 '인증 정보'를 SP에게 전달
    5. 로그인 처리가 완료 되어 SP를 사용할 수 있다.

이후, SP 사용 시

    1. 사용자가 SP를 사용하려 한다.
    2. 사용자의 세션 정보가 SP에 남아있지 않아서, SP는 사용자를 IdP로 redirect 시킨다.
    3. 사용자의 세션 정보가 IdP에 남아있다. 따라서, IdP는 사용자를 SP로 다시 redirect 시키며, 동시에 사용자의 '인증 정보'를 SP에 전달.
    4. 로그인 처리가 완료되어 SP 사용이 가능하다.

# JWT(JSON Web Token)

- 토큰처럼 사용할 수 있도록 JSON을 인코딩하고 서명한 것.
- 서버로부터 독립적으로 기능하며 짧은 시간만 작동한다.
- 스스로 만료되는 일회성 토큰으로 사용된다.

## JWT의 장점
서버 요청자에게 특정 기능을 허가해줄지 판단하기 위해 필요로 하는 모든 데이터를 JWT 안에 담아두려 한다. 서명 확인하는 것 외에 서버에서 인증 작업 하지 않아도 된다. 또한, JWT 내부에 만료 시간을 넣어서 스스로 만료되도록 할 수 있다.

## JWT의 단점
서버의 책임을 덜어주지만, 동시에 서버의 통제력도 빼앗아간다.



## 참고 : Claim 기반의 토큰 이용한 API 권한 인증 흐름
	1. 사용자를 인증한 다음, 토큰을 생성
	2. 토큰을 별도로 저장하지 않는다. 토큰에 연관되는 사용자 정보나 권한 등을 토큰 자체에 넣어서 저장.
	3. API 호출 : callAPI(params, token)
	4. API서버는 토큰 내 들어 있는 사용자 정보를 가지고 권한 인가 처리를 하고 결과를 리턴.


## Refresh Token
AccessToken의 수명이 만료되었을 때, 손쉽게 토큰을 다시 발급하기 위한 토큰
	1. AccessToken과 RefreshToken을 함께 발행한다.
	2. AccessToken으로 ResourceServer에 접속한다.
	3. Invalid Token Error 발생
	4. Authorization Server로 RefreshToken 전송
	5. 다시 AccessToken을 발급받는다.

[그림 참고](https://tools.ietf.org/html/rfc6749#section-1.5)



(참고: [jwt 공식 페이지](https://jwt.io/introduction/), [JWT 개념](https://harfangk.github.io/2016/10/16/what-is-jwt-ko.html),[JWT 개념](https://sanghaklee.tistory.com/47), [claim 기반 권한 인증 흐름](https://bcho.tistory.com/999))