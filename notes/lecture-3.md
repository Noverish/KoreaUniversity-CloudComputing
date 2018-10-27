
# Lecture 3


## Basic Concepts and Terminology
### 1. Cloud
- 확장 가능한 IT 리소스를 원격으로 provisioning 하도록 설계된 고유 IT 환경
- 분산형 IT 리소스 집합에 대한 원격 액세스를 제공하는 네트워크의 네트워크
- 인터넷은 많은 IT 리소스에 대한 열린 접근을 주지만 Cloud는 측정되는 IT 리소스에 대한 닫힌 접근을 줌
### 2. Scaling
- 사용량에 따라 리소스를 늘리거나 줄일 수 있음
- Horizontal Scaling
  - 같은 타입의 리소스를 더 할당하거나 할당 해제 함
  - 더 할당 하는 것을 scaling out, 할당 해제 하는 것을 scaling in
- Vertical Scaling
  - 용량이 더 크거나 작은 것으로 교체
  - 용량이 큰 것으로 교체 하는 것을 scaling up, 더 작은 것으로 교체하는 것을 scaling down
![table 3.1](https://raw.githubusercontent.com/Noverish/KU-CC-2018-Fall/master/notes/images/table-3.1.png)
### 3. Cloud Service
- 클라우드를 통해 원격으로 접근할 수 있는 모든 IT 리소스
- 클라우드에 있는 Web Service와 Virtual Server 등


## Goals and Benefits
### 1. 투자 및 비용 절감
- 클라우드 공급자는 대량 구매를 기반으로하는 비즈니스 모델을 가짐
- 초기 IT 리소스 투자 비용 완전 제거 또는 감소
- 이득
  - 짧은 시간 동안 낸 만큼 쓰고 다 쓰면 반납
  - 필요하면 사용할 수 있는 무제한 컴퓨팅 리소스가 있다는 생각 때문에 준비 필요성이 줄어듬
  - 세분화 된 IT 리소스 할당을 할 수 있음 (하드에 기가 단위로 용량 추가)
  - 인프라룰 추상화 했기 때문에 어플리케이션이 장치나 위치에 종속적이지 않고 자유롭게 이동 가능
### 2. Increased Scalability
- 클라우드 소비스의 설정에 의해 즉각적으로 동적으로 IT 리소스 할당 가능
- 예측 불가능한 사용량을 항상 충족할 수 있기 때문에 잠재적인 손실을 방지 할 수 있음
### 3. Increased Availability and Reliability
- 고가용성의 IT 리소스에 장기간 접근 가능
- 클라우드 제공자는 고가용성을 보장하는 탄력있는 IT 리소스를 제공
- 안정성이 높아진 IT 리소스는 예외 상황을 더 잘 피하거나 복구 할 수 있음
- 클라우드 환경의 모듈형 구조는 안정성을 높이는 광범위한 에러 복구를 지원


## Risks and Challenges
### 1. Increased Security Vulnerabilities
- IT 리소스를 원격으로 사용하려면 클라우드 소비자가 외부 클라우드를 포함하도록 신뢰 경계를 확장해야함    
=> 추가적인 취약점 없이 신뢰 경계를 넓히는 것은 어려움
- 클라우드 기반 IT 리소스를 공유하는 다른 클라우드 소비자와 신뢰 경계가 겹칠 수 있음    
=> 겹친 신뢰 경계와 더 많은 데이터가 노출 되는 것은 악의적 클라우드 소비자가 IT 리소스를 공격하거나 비즈니스 정보를 훔치거나 피해를 입힐 수 있는 더 큰 기회를 제공
### 2. Reduced Operational Governance Control
- on-premise IT 리소스 보다 덜 지배적인 자원을 할당 받음
- 신뢰할 수 없는 클라우드 제공자가 약관을 어길 수 있음
- 클라우드 제공자와 소비자 간의 먼 물리적 거리때문에 둘 사이의 통신이 위협 받을 수 있음
### 3. Limited Portability Between Cloud Providers
- 클라우드 컴퓨팅 산업 내에 확립된 업계 표준이 없음
### 4. Multi-Regional Compliance and Legal Issues
- 제 3의 클라우드 제공자가 편리하고 적당한 지리학적 위치에 데이터 센터를 지음으로써 해당 데이터 센터의 국가에서의 개인 정보 보호관련 법을 위반할 수가 있음
- 일부 국가는 특정 데이터를 정부 기관에 공개해야 하는 법을 가지고 있음


resilient : 회복력있는
allotted : 할당된
fluctuate : 계속 변동하는
proprietary : 소유자의
affordable : 알맞은
pertain : 적용되다