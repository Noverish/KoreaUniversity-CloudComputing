
# lecture 5

## Broadband Networks and Internet Architecture

## Data Center Technology
- 최신 데이터 센터는 서버, 데이터베이스, 네트워킹 및 통신 장치 및 소프트웨어 시스템과 같은 중앙 집중식 IT 리소스를 수용하는 데 사용되는 특수 IT 인프라

### (1) Virtualization
- 물리적 IT 리소스와 가상화 IT 리소스로 구성
- 물리적 IT 리소스 계층 : 하드웨어 시스템 및 해당 운영 체제와 함께 컴퓨팅/네트워크 시스템 및 장비를 수용하는 시설 인프라
- The resource abstraction and control of the virtualization layer :  물리적 컴퓨팅 및 네트워킹 IT 리소스를 할당, 운영, 릴리스, 모니터링 및 제어가 더 쉬운 가상화된 구성 요소로 추상화하는 가상화 플랫폼을 기반으로 하는 운영 및 관리 툴로 구성

### (2) Standardization and Modularity
- 조달, 획득, 배치, 운영 및 유지보수 프로세스에 규모의 경제를 활성화하기 때문에 투자 및 운영 비용을 절감하기 위한 주요 요구사항

### (3) Automation
- 데이터 센터에는 프로비저닝, 구성, 패치 적용 및 모니터링과 같은 작업을 감독 없이 자동화하는 특수 플랫폼이 있습니다.

### (4) Remote Operation and Management
- 데이터 센터의 IT 리소스에 대한 대부분의 운영 및 관리 작업은 네트워크의 원격 콘솔 및 관리 시스템을 통해 명령됩니다.

### (5) High Availability
- 어떤 형태의 데이터 센터 운영 중단이라도 서비스를 사용하는 조직의 비즈니스 연속성에 큰 영향을 미치기 때문에 데이터 센터는 가용성을 유지하기 위해 점점 더 높은 수준의 이중화를 통해 작동하도록 설계되었습니다.

### (6) Security-Aware Design, Operation, and Management
- 데이터 센터는 비즈니스 데이터를 저장하고 처리하는 중앙 집중식 구조이므로 물리적/논리적 액세스 제어 및 데이터 복구 전략과 같은 보안 요구 사항은 데이터 센터에 대해 철저하고 포괄적이어야 합니다.

### (7) Facilities
- 데이터 센터 시설은 특수 컴퓨팅, 스토리지 및 네트워크 장비를 갖춘 맞춤형 설계 위치입니다.

### (8) Computing Hardware
- 데이터 센터의 많은 처리량은 종종 상당한 컴퓨팅 성능과 스토리지 용량을 지닌 표준화된 일반 서버에 의해 수행됩니다.
- 여러 컴퓨팅 하드웨어 기술이 이러한 모듈형 서버에 통합되어 있습니다.
  - 표준화된 랙으로 구성된 랙 마운트 폼 팩터 서버 설계
  - 다양한 하드웨어 처리 아키텍처 지원
  - 전력 효율적인 멀티 코어 CPU 아키텍처
  - 핫 스왑이 가능한 이중 구성 요소
- blade 서버 기술과 같은 컴퓨팅 아키텍처는 랙 임베디드 물리적 상호 연결(blade enclosures), fabrics(switches), 공유 전원 공급 장치 및 냉각 팬을 사용합니다.

### (9) Storage Hardware
- 데이터 센터에는 상당한 스토리지 용량 요구사항을 충족하기 위해 방대한 양의 디지털 정보를 유지하는 전문 스토리지 시스템이 있습니다.
- 스토리지 시스템은 보통 다음과 같은 기술을 가지고 있습니다.
  - Hard Disk Arrays - redundant arrays of independent disks (RAID)
  - I/O Caching
  - Hot-Swappable Hard Disks
  - Storage Virtualization
  - Fast Data Replication Mechanisms
- Networked storage devices
  - Storage Area Network (SAN)
  - Network-Attached Storage (NAS)

### (10) Network Hardware
- 데이터 센터에는 여러 수준의 연결을 지원하기 위해 광범위한 네트워크 하드웨어가 필요합니다.
  - Carrier and External Networks Interconnection
  - Web-Tier Load Balancing and Acceleration
  - LAN Fabric
  - SAN Fabric
  - NAS Gateways

## Virtualization Technology
- 가상화는 물리적 IT 리소스를 가상 IT 리소스로 전환하는 프로세스입니다.
- 대부분의 IT 리소스는 가상화를 할 수 있음
  - 가상 서버
  - 가상 저장 장치 또는 가상 디스크
  - VLAN
  - Power - Virtual UPSs
- 가상화 소프트웨어는 호스트 또는 물리적 호스트라고 하는 물리적 서버에서 실행되며, 기본 하드웨어는 가상화 소프트웨어에서 액세스할 수 있습니다.
  - Virtual machine manager or a virtual machine monitor (VMM)
  - hypervisor

### (1) Hardware Independence
- 고유한 IT 하드웨어 플랫폼에 운영 체제의 구성 및 애플리케이션 소프트웨어를 설치하면 많은 소프트웨어-하드웨어 종속성이 발생합니다.
- 가상화는 고유한 IT 하드웨어를 에뮬레이션되고 표준화된 소프트웨어 기반 복사본으로 변환하는 프로세스입니다.
- 하드웨어 독립성을 통해 가상 서버를 다른 가상화 호스트로 쉽게 이동할 수 있습니다.

### (2) Server Consolidation
- 가상화 소프트웨어에서 제공하는 조정 기능을 사용하면 동일한 가상화 호스트에서 여러 가상 서버를 동시에 생성할 수 있습니다.
- 가상화 기술을 통해 여러 가상 서버가 하나의 물리적 서버를 공유할 수 있습니다.
- 사용 가능한 IT 리소스의 하드웨어 활용률, 로드 밸런싱 및 최적화를 늘리는 데 사용됩니다.

### (3) Resource Replication
- 가상 서버는 하드 디스크 컨텐츠의 이진 파일 복사본이 포함된 가상 디스크 이미지로 생성됩니다. - 이러한 가상 디스크 이미지는 호스트의 운영 체제에서 액세스할 수 있으며 붙여넣기를 통해 가상 서버를 복제, 마이그레이션 및 백업할 수 있습니다.
  - 일반적으로 가상 하드웨어 기능, 게스트 운영 체제 및 추가 애플리케이션 소프트웨어를 포함하도록 구성된 표준화된 가상 시스템 이미지 생성
  - 가상 시스템의 새 인스턴스 마이그레이션 및 배포에서 민첩성 향상
  - 롤백 기능: 가상 서버의 메모리 및 하드 디스크 이미지의 상태를 호스트 기반 파일에 저장하여 VM 스냅샷을 즉시 생성하는 기능
  - 효율적인 백업 및 복원 절차를 통한 비즈니스 연속성 지원 및 중요한 IT 리소스 및 애플리케이션의 여러 인스턴스 생성

### (4) Operating System-Based Virtualization
- 호스트 운영 체제라고 하는 기존 운영 체제에 가상화 소프트웨어 설치
- 가상화를 통해 구현되는 하드웨어 독립성을 통해 하드웨어 IT 리소스를 보다 유연하게 사용할 수 있습니다.
- 가상화 소프트웨어는 운영에 고유한 소프트웨어가 필요한 하드웨어 IT 리소스를 다양한 운영 체제와 호환되는 가상화된 IT 리소스로 변환합니다.
- 운영 체제 기반 가상화는 다음과 같은 성능 오버헤드와 관련된 요구 사항 및 문제를 가져올 수 있습니다.
  - 호스트 운영 체제는 CPU, 메모리 및 기타 하드웨어 IT 리소스를 사용합니다.
  - 게스트로 운영 체제로부터 발생한 Hardware-related 호출이 하드웨어로 가거나 올 수 있게 여러겹을 통과할 필요가 있다.
  - 라이센스는 일반적으로 각 게스트 OS에 대한 개별 라이센스 외에도 호스트 OS에 필요합니다.
- 가상화 계층을 구현하면 전체 시스템 성능에 부정적인 영향을 미칩니다.

### (5) Hardware-Based Virtualization
- 이 옵션은 호스트 운영 체제를 우회하기 위해 물리적 호스트 하드웨어에 직접 가상화 소프트웨어를 설치하는 것을 나타냅니다.
- 가상화 소프트웨어를 일반적으로 하이퍼바이저라고 합니다.
- 하이퍼바이저가 하드웨어 관리 기능을 처리하여 가상화 관리 계층을 설정하는 얇은 소프트웨어 계층으로 존재합니다.
- 하드웨어 기반 가상화의 주요 문제 중 하나는 하드웨어 장치와의 호환성입니다.
  - 가상화 계층은 호스트 하드웨어와 직접 통신하도록 설계되었습니다.
  - 하드웨어 장치 드라이버는 운영 체제와 달리 하이퍼바이저 플랫폼에서 사용할 수 없습니다.

### (6) Virtualization Management
- 최신 가상화 소프트웨어는 관리 작업을 자동화하고 가상화된 IT 리소스에 대한 전반적인 운영 부담을 줄일 수 있는 몇 가지 고급 관리 기능을 제공합니다.

### (7) Other Considerations
- 성능 오버헤드 - 리소스 공유 및 복제에 거의 사용되지 않는 워크로드가 많은 복잡한 시스템에는 가상화가 적합하지 않을 수 있습니다.
- 특수 하드웨어 호환성 - 전문 하드웨어를 배포하는 많은 하드웨어 공급업체는 가상화 소프트웨어와 호환되는 장치 드라이버 버전을 가지고 있지 않을 수 있습니다.
- 이식성 - 다양한 가상화 솔루션과 함께 작동하는 가상화 프로그램의 관리 환경을 설정하는 프로그래밍 방식 및 관리 인터페이스는 비호환성으로 인한 휴대성 격차를 일으킬 수 있습니다.

## Web Technology

### (1) Basic Web Technology
- 웹의 두 가지 기본 구성요소는 웹 브라우저 클라이언트와 웹 서버입니다.
- 웹의 기술 아키텍처를 구성하는 세 가지 기본 요소
  - Uniform Resource Locator (URL) - 웹 기반 리소스를 가리키는 식별자를 만드는 데 사용되는 표준 구문
  - Hypertext Transfer Protocol (HTTP) - 이것은 월드 와이드 웹 전체에 걸쳐 콘텐츠와 데이터를 교환하는 기본 통신 프로토콜이다.
  - Markup Languages (HTML, XML) - 마크업 언어는 웹 중심 데이터와 메타데이터를 표현하는 가벼운 수단을 제공합니다.

### (2) Web Applications
- 기본 3계층 모델에 기반한 웹 애플리케이션을 위한 공통 아키텍처 추상화
  - 첫 번째 계층을 사용자 인터페이스를 나타내는 프레젠테이션 계층이라고 합니다.
  - 중간 계층은 애플리케이션 로직을 구현하는 애플리케이션 계층입니다.
  - 세 번째 계층은 영구 데이터 저장소로 구성된 데이터 계층입니다.

## Multitenant Technology
- 다중 사용자가 동일한 애플리케이션 논리에 동시에 액세스할 수 있도록 멀티테넌트 애플리케이션 설계가 생성되었습니다.

### 멀티테년트 어플리케이션의 기능
- User Interface - 테넌트는 애플리케이션 인터페이스에 대해 전문화된 "모양 및 느낌"을 정의할 수 있습니다
- Business Process - 테넌트는 애플리케이션에 구현된 비즈니스 프로세스의 규칙, 논리 및 워크플로우를 사용자 정의할 수 있습니다.
- Data Model - 테넌트는 응용 프로그램 데이터 구조에 필드를 포함, 제외 또는 이름을 변경하도록 응용 프로그램의 데이터 스키마를 확장할 수 있습니다.
- Access Control - 테넌트는 사용자 및 그룹에 대한 액세스 권한을 독립적으로 제어할 수 있습니다.

### 멀티테넌트 애플리케이션의 특징
- Usage Isolation - 한 테넌트의 사용 동작은 다른 테넌트의 애플리케이션 가용성과 성능에 영향을 주지 않습니다.
- Data Security - 테넌트는 다른 테넌트에 속하는 데이터에 액세스할 수 없습니다.
- Recovery - 각 테넌트의 데이터에 대해 백업 및 복원 절차가 별도로 실행됩니다.
- Application Upgrades - 공유 소프트웨어 아티팩트의 동시 업그레이드로 인해 테넌트는 부정적인 영향을 받지 않습니다.
- Scalability - 애플리케이션은 기존 테넌트의 사용 증가 및/또는 테넌트 수의 증가를 수용할 수 있도록 확장할 수 있습니다.
- Metered Usage - 테넌트는 실제로 소비되는 애플리케이션 처리 및 기능에 대해서만 청구됩니다.
- Data Tier Isolation - 테넌트는 개별 데이터베이스, 테이블 및/또는 스키마를 다른 테넌트와 분리할 수 있습니다.

### Multitenancy vs Virtualization
- Virtualization : 서버 환경의 여러 가상 복사본을 단일 물리적 서버에서 호스팅할 수 있습니다. 각 복사본은 다른 사용자에게 제공할 수 있으며, 독립적으로 구성할 수 있으며 자체 운영 체제와 애플리케이션을 포함할 수 있습니다.
- Multitenancy : 애플리케이션을 호스팅하는 물리적 서버 또는 가상 서버는 여러 사용자가 사용할 수 있도록 설계되었습니다. 각 사용자는 애플리케이션을 독점적으로 사용하는 것처럼 느낀다.

## Service Technology

### Web Services
- 일반적으로 'SOAP-based'라는 접두어가 붙는다.
- 웹 서비스의 핵심 기술은 다음과 같은 산업 표준들이 있다.
  - Web Service Description Language (WSDL)
  - XML Schema Definition Language (XML Schema)
  - SOAP – Formerly known as the Simple Object Access Protocol
  - Universal Description, Discovery, and Integration (UDDI)
- 이 네 가지 기술은 종합적으로 제1세대 웹 서비스 기술을 구성한다.

### Rest Services
- REST 서비스는 월드 와이드 웹의 속성을 모방하기 위해 서비스 아키텍처를 형성하는 일련의 제약 조건에 따라 설계되었습니다.
- 6개의 REST 디자인 제약 사항
  - Client-Server
  - Stateless
  - Cache
  - Interface/Uniform Contract
  - Layered System
  - Code-On-Demand

### Service Agents
- 런타임에 메시지를 가로채도록 설계된 이벤트 기반 프로그램.
- Active service agents : 메시지 내용을 가로채거나 읽을 때 작업을 수행합니다.
  - 메시지 내용을 변경하거나 메시지 경로를 변경해야 함
- Passive service agents : 메시니 내용을 변경하지 않음
  - 메시지를 읽은 다음 일반적으로 모니터링, 로깅 또는 보고 목적으로 내용의 특정 부분을 캡처할 수 있습니다.
- 클라우드 기반 환경은 시스템 레벨 및 맞춤형 서비스 에이전트를 사용하여 탄력적인 확장 및 사용 비용 청구와 같은 기능을 즉각적으로 수행하는 데 필요한 많은 런타임 모니터링 및 측정을 수행하는 데 크게 의존하고 있습니다.

procurement : 조달    
commodity : 상품    
substantial : 튼튼한
consolidation : 통합
coordination : 조정