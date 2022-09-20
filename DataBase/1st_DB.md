# 1st_week_데이타베이스: Why Databases?

## 1. Why use a Database?
### ★ Prevalence of DataBase
- 성공적인 사이트 운영뒤에는 강력한 데이터베이스가 필요함 : 가지고있는 정보량이 매우 많기때문에 이를 통합적으로 관리하고 저장할 데이터베이스가 필요한것임
- 예) Amazon, E-consumer, Google's search engine 등에서 다수 활용

### ★ Data Mangagement Example
내가 만약 DVD 렌탈 숍을 차리고할때 우리는 언제 고객들이 그것을 빌려갔는지, DVD 대여 만기날짜에 가까워지고 있는 것은 어떤건지, Blue-ray의 재고는 얼마나 남았는지와 같은 정보들을 관리하고 저장할만한 시스템이 필요함. 그 방법이란 뭘까?

#### "File-based" System
  + File 기반 정보 관리가 하나의 대안이 될 수 있음.
  + 파일에다가 dvd 이름은 뭐고 고객 정보는 뭔지 같은 정보들을 저장해두면 됨(메모장 같은 곳에 일일이 정보들을 타이핑해서 넣어둔다고 생각하면됨)
  + Text editors are easy to use(텍스터 에디터는 사용하기 쉬움)
  + Simple to insert/delete a record(레코드-정보를 담은 행-을 쉽게 삽입/삭제 가능)
  + 하지만 이런 파일기반 시스템에는 한계가 존재!!

#### File 기반 데이터 관리 과정에서 마주치는 여러 문제점들(Complications) & 필요한 technique  
1. Queries(질의): 홍길동이 대여를 한적있나요? 만료된 대여항목이 존재하나요? 같은 질문을 던짐으로서 원하는 대답을 얻어냄
    - Robust, sophisticated query language (정교한 질의 언어가 필요)
    - Clear separation between data organization (schema) and data (데이터와 데이터 구조간의 확실한 분리)
    - Schema / DML / SQL
2. Integrity(무결성): 데이터베이스에 저장된 데이터 값과 그것이 표현하는 현실 세계의 실제값이 일치하는 정확성, 데이터의 일관성과 통합성을 유지해야함
    - Enforce constraints (제약조건) to permit only valid information to be input. (input되는 정보들에 대해 설정한 제약조건에 맞는 데이터만 받아들이도록함)
    - Integrity constraints / Types
3. Update(갱신): 데이터를 모든 레코드나 일부에 저장하고 삭제하고 갱신한다.
    - Ability to manipulate the way data is organized (데이터가 조직화되는 방식을 조작하는 능력)
    - DDL
4. Multiple Users(다중 사용자): 비디오 가게에서 다수의 알바가 데이터에 접근할 수 있을거임. 서로 작업을 하고 이를 덮어씌우는 과정에서 의도치않은 문제가 발생할 수 있음
    - 다양한 writers와 readers를 지원
    - 데이터의 갱신은 꼭 serial하게 일어나야한다.
    - Serializability / Concurrency control
5. Crashes(크래시): 데이터끼리의 충돌문제해결, 날아간 데이터를 어떻게 복구할 것인지
    - 데이터 업데이트 과정에서 crash가 발생한다면 일관성(consistent)을 유지하지 못할 수 있음
    - Must update on all-or-non basis(a.k.a, atomicity)
    - commit(커밋) or rollback(롤백) if necessary (특정 시점으로 복원할 수 있도록 커밋과 롤백이 지원되어야한다)
    - Transactions / Commit / Rollback / Recovery
6. Data Physically Separate(물리적으로 떨어져있는 데이터): txt를 이용한 데이터를 서로 병합해야할 경우에 같은 이름의 사용자가 여러명 존재한다던가, 특정 고객 정보가 없다던가할때 문제가 발생할 수 있음
    - Uniquely identify each customer.(각 사용자가 unique하게 인식되어야함)
    - Make sure we have information on customers that rent the movie.(유저 데이터가 확실하게 확보되어있어야함)
    - Joins / Keys / Foreign keys / Referential integrity
7. Security(보안): 데이터 보안 문제
    - Ability to control who has access to what information. (누가 데이터에 접근하는지 파악해야한다.)
    - Security / Views
8. Efficiency(효율성): 데이터는 계속해서 쌓이게 되면서 enormous해질 것이다. text editor로는 지속적인 관리가 힘듬.
    - query performace를 개선하기 위한 새로운 data structure 필요
    - 시스템이 자동적으로 speed를 개선시키기위한 query를 조정해나가야함.
    - Ability of system to scale to handle huge datasets.(많은 양의 데이터를 관리하기 위한 scale 관리하기 위한 시스템이 필요하다.)
    - Indexes / Query optimization / Database tuning
9. New needs
    - 앞으로 어떤 데이터들이 필요한지 그리고 현재 데이터를 분석했을때 어떤 가치가 있는 정보를 추론해낼지에 관한 기술들이 필요함
    - Collect and analyze summary data.(요약 데이터)
    - Use computer to mine for interesting trends and predict future trends.(흥미로운 트렌드를 캐거나 예측)
    - Support success to data by sophisticated programs.(정교한 프로그램을 통한 데이터 관리 지원)
    - Data mining / Big Data Analytics / Data warehouses / Database API
