
## 1. Distributed deadlocks
- 데드락은 락을 concurrency control에 쓰는 한 서버에서 일어날 수 있다.
- 서버는 데드락을 방지, 감지, 해결 할 수 있어야 한다.
- timeout을 써서 데드락을 해결하는 방법은 어설프다.
- 대부분의 데드락 감지 방식은 wait-for 그래프의 cycle을 찾으며 작동한다.
  - Node : transaction and objects
  - Edge : 한 object가 transaction을 들고 있는 것 또는 object를 기다리는 transcaction
  - 분산 데드락 : global wait-for 그래프에 사이클이 있다.

서버가 3대 있다. X Y Z
X : A
Y : B
Z : C, D
를 관리

local wait-for 그래프가 락 매니저에 의해 각 서버에 만들어 진다.

### 1.1. Centralized deadlock detection
- 한 서버가 global deadlock detector 역할을 맡는다.
- 각 서버는 local wait-for graph의 복사본을 보낸다.
- detector가 cycler을 감지 했을 경우, 어떻게 해결할지 정하고, 서버에게 요청을 취소하게 함으로써 데드락을 해결한다.
- 좋은 아이디어가 아니다, 한 서버에 의해 수행 되기 때문
- 문제 : 낮은 가용성, fault tolerance 낮다. 키울 수 없고 그래프를 자주 보내야 하는 비용

### 1.2. Phantom deadlocks
- 데드락이 감지 되었지만 실제로는 아니다.
- 데드락 감지가 시간이 좀 걸려서 요청이 금방 풀리는 걸 감지 못한다.

### 1.3. Edge chasing (path pushing)
- global wait-for 그래프가 만들어지지 않고, 각각의 서버가 몇 개의 edge 정보를 알고 있다.
- 서버들은 message called probe를 전달하는 것을 통해 cycle을 찾는다.
- probe는 wait-for 그래프의 요청으로 이루어져 있다.


2
데드락
데드랑 avoidance는 힘들다 : future knowledge을 알기 어렵다.
cycle을 찾는 것이 detection이다
hold와 wait를 edge로 표현
분산시스템에서는 global wait-for graph

7
우선 순위 기반 edge chasing
global wait-for 그래프를 만든다
메시지의 형태를 probe

11
prority가 높은 데에서 낮은 쪽으로만 보낸다.