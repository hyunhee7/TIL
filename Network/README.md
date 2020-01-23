# Network

아래 내용은 https://net123.tistory.com/384?category=605873 를 통해 공부하고 정리한 내용입니다.

## 프로토콜
* 데이터 전송 시 필요한 규칙 및 약속을 미리 정의한 도구
* 네트워크가 구성되기 이전에 미리 정의되거나 관리자에 의해 선택되어야 한다.

그럼 프로토콜 어떻게 사용할까?

## 인캡슐레이션
데이터 보내기 위해 포장하는 과정

* HTTP 보내기 위해 TCP라는 프로토콜 사용
* 위에 것을 보내려면 IP 사용
* 위에 것 보내려면 Ethernet 사용

	Ethernet | IP | TCP | HTTP
    
* 헤더 : Ethernet, IP, TCP
	이런식으로 전송을 위해 붙는 프로토콜을 '헤더'라고 한다. 헤더 정보 속 주소를 보고 도착지로 움직인다.
    
* HTTP
    * TCP 헤더 20byte
    * IP 헤더 20byte
    * Ethernet 헤더 14byte

* DNS
    * UDP
    * IP
    * Ethernet

## 네트워크 유형

### LAN(Local Area Network)
* 전송 장비
	* 허브
	* 스위치
	* 케이블(랜선)
	* 무선 공유기

* 데이터 전송 프로토콜 
	* Ethernet (안에서 이동하게 쓰는 것)
		출발지 MAC주소, 도착지 MAC주소, type(내부 들어있는 데이터 타입)

### WAN(Wide Area Network)
연결되는 거리가 멀다. LAN과 LAN을 연결한다.
ISP업체를 통해 연결. 인터넷과 네트워크망을 임대해주는 업체. WAN은 일반적으로 ISP를 통해서 연결된다. 대표적인 ISP로는 KT, SK, LG가 있다.

* 사용 프로토콜
	* HDLC (기본값)
	* frame-relay
	* PPP
	* 요즘에는 Ethernet 사용, 구분이 없음.
		* FastEthernet 100M
		* GigabitEthernet 1000M
		* 10GigabitEthernet 10000M

* 관리는 ISP업체가 담당한다. 


### 인터넷
* 전세계적으로 연결된 네트워크 망 서비스
* TCP/IP가 반드시 필요

### Intranet
* 기업 내부용으로 사용하는 네트워크 서비스
* 회사 게시판, 공지사항, 자료 공유 ...

