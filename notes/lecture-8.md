
# lecture 8

## Automated Scaling Listener
- 동적 확장을 위해 클라우드 서비스 소비자와 클라우드 서비스 간의 통신을 모니터링하고 추적하는 서비스 에이전트
- 일반적으로 방화벽 근처인 클라우드 내에 배치되어 워크로드 상태 정보를 자동으로 추적
- 워크로드는 소비자가 생성하는 클라우드 요청의 볼륨 또는 특정 유형의 요청에 의해 트리거된 백엔드 처리 수요에 의해 결정될 수 있음
- 워크로드 변동 상황에 대한 다양한 유형의 대응 제공
  - 클라우드 소비자가 이전에 정의한 매개 변수를 기반으로 IT 리소스 자동 확장 (auto-scaling)
  - 워크로드가 현재 임계값을 초과하거나 할당된 리소스보다 낮을 경우 클라우드 소비자 자동 알림
- Scaling-Down : 가상 서버는 더 낮은 성능 구성으로 확장되는 동안 동일한 물리적 호스트 서버에 계속 상주합니다.
- Scaling-Up : 가상 서버의 용량은 원래 물리적 호스트 서버에서 두 배로 증가합니다. 원래 호스트 서버가 오버 커밋된 경우 마이그레이션은 런타임에 자동으로 수행되므로 가상 서버를 종료할 필요가 없습니다.

## Load Balancer
- 로드 밸런서는 성능 및 QoS 규칙 및 매개 변수 세트로 프로그래밍 또는 구성되며, IT 리소스 사용을 최적화하고, 과부하를 방지하고, 처리량을 최대화하는 일반적인 목표를 가지고 있습니다.

### 정의
- 수평적 확장에 대한 일반적인 접근 방식은 둘 이상의 IT 리소스 간에 워크로드의 균형을 조정하여 단일 IT 리소스가 제공할 수 있는 수준을 뛰어넘는 성능과 용량을 늘리는 것입니다.
- 로드 밸런서 메커니즘은 기본적으로 이 전제를 기반으로 하는 논리가 있는 런타임 에이전트입니다.

### Specialized runtime workload distribution functions
- Asymmetric Distribution : 처리 용량이 큰 IT 리소스에 더 많은 워크로드가 제공됨
- Workload Prioritization : 워크로드가 우선 순위에 따라 예약, 대기, 폐기 및 배포됩니다.
- Content-Aware Distribution : 요청이 요청 컨텐츠에 따라 다른 IT 리소스에 배포됩니다.


## SLA Monitor

## Pay-Per-Use Monitor

## Audit Monitor

## Failover System

## Hypervisor

## Resource Cluster

## Multi-Device Broker

## State Management Database

fluctuation : 변동
audit : 회계 감사    
regulatory : 단속력을 지닌    
contractual : 계약상의    
obligations : 의무    