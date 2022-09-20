# 2nd_week_데이타베이스: Chapter1. Databases and Database Users
## 1. Introduction
### ★ Basic Definition
- What is "Data"?
  + 기록되어질 수 있고 함축적 의미를 가진 알려진 사실
  + 엄밀하게 말해면 거짓된 정보가 포함되면 data가 아님. fact로부터 추론이 가능한 자료.
  + 이름, 주소, 지인의 전화번호가 포함됨
- What is "Database"
  + 서로 관련이 있는 데이터(related data)의 organized collection이다. (연관된 자료들을 잘 조직하여 모아둔 것)
- Database Management System (DBMS)?
  + database를 만들고 유지하는데 유저가 사용하는 "software package/system" (ex. Oracle, MySQL, ..)
- Database system?
  + Database + Database Management System (+ Database applications: DB를 활용하는데 추가적으로 필요한 application들)

### ★ Types of Databases and Database Applications
- Traditional Applications
  + 숫자와 문자로 구성된 데이터베이스: 주로 금융권, 도서관, 예약 시스템에서 다수 사용
- More Recent Applications
  + 멀티미디어 데이터베이스
  + 지질학 정보를 담은 데이터베이스
  + 생물학과 게놈 데이터베이스
  + 등등... 다양한 용도와 영역에서 데이터베이스가 사용되고 있다.

### ★ Recent Develpments
- 과거와 달리 새로운 용도로 사용되는 데이터베이스가 늘었는데 특히 소셜 미디어 사이트(페이스북, 링크드인, ..)에서 "nontraditional" data (posts, tweets, images and video clips)를 데이터베이스에 저장하는 빈도가 늘었다. -> 이러한 형태의 데이터를 저장하기위한 데이타베이스 시스템의 구축이 필요했고 NoSQL (Not-only SQL) systems 혹은 big data storge systems가 필요하게 되었다.
- 구글, 아마존, 야후 등과 같은 검색엔진에서는 이런 다양한 데이터를 저장할 수 있는 시스템을 사용하곤 했음 - 수만개의 기계로 이루어진 큰 data center들에 의해 작동되는 cloud storage를 사용하고 제공하기도 함.

1. NoSQL DB
- No Structure Query Language (비구조화 질의 언어)
- 기능과 특징이 다른, 데이터 관리 기술의 집합에 사용하는 명칭이다.
- NoSQL 데이터베이스는 행과 테이블을 사용하는 관계형(SQL) 데이터베이스보다 훨씬 다양한 방식으로 빠르게 바뀌는 대량의 비정형 데이터를 처리할 수 있다는 점을 강조하기 위해 “비관계형”, “NoSQL DB” 또는 “non-SQL”이라고도 합니다. (출처: Microsoft Azure)
- SQL Database는 정확한 정의를 가지지만 NoSQL은 그렇지 않다.
- 다양한 특징
  + 고성능의 쓰기와 대규모의 확장성을 지원 (ex. Mongo DB, eleasticsearch, Caasandra)
  + writing data를 위한 정의된 스키마를 요구하지 않음.
  + Primarily eventually-consistent by default
  + 현대의 다양한 프로그래밍 언어와 툴을 지원함
  + 분산 시스템으로 불리는, 실패가 용인되는 환경을 제공 (한 노드가 죽어도 다른 노드가 작동해서 처리 가능)
2. Hadoop
- 빅데이터 처리를 위한 Mapreduce Programming Model
3. Apache Spark
- 하둡의 latency 문제를 해결한 model
- 메모리르 추가적으로 사용한다.

## 2. Database System Environment (데이터베이스 시스템 환경)
### ★ A "Simplified" Database System Environment
<img width="400" height="550" src="https://user-images.githubusercontent.com/97028605/191275251-9cd84f85-d365-48d6-95e4-009d6595e1ce.jpeg"></img>

1) Applications interact with a DB by generating:
  - Query(질의): 찾고자하는 데이터를 검색한다. (읽기)
  - Transaction(트랜색션): 어떤 데이터를 쓰거나 데이터베이스에서 atomically하게 읽어온다. (읽기, 갱신, 삭제)
2) Data protection을 위해서 applications은 허가되지 않은 사용자에 대해서 접근을 제한하여야 한다.
3) Applications은 사용자 요구에 맞추어서 DB를 지속적으로 changing해야 한다.

### ★ Typical DBMS Functionality (일반적인 DBMS 기능) - 거의 DB의 엄마같은 거임
1) 특정 데이터베이스에 대한 데이터들의 types, 데이터베이스 구조 그리고 제약조건들을 정의한다.
2) 물리적으로 2차 저장소 (HDD, SSD: 비휘발성에 대용량이기 때문) 에 데이터베이스 content를 만들고 불러오는 기능을 한다.
3) 데이터베이스를 조작한다
  - Retrieval(검색): querying, generating reports
  - Modification(수정): 내용을 추가, 삭제 그리고 업데이트
  - Access(접근): Web application을 통해서 database에 접근하도록 한다.
4) concurrent user and applications가 처리하고 공유헐 수 있도록 돕는다.(단, 모든 데이터가 타당하고 consistent하도록 유지)
5) 이처럼 정의, 저장, 관리, 다수 유저를 위한 서비스 제공과 같은 다양한 역하릉ㄹ 하는것이 DBMS

### ★ Database Design Phases (데이터베이스를 디자인하는 4가지 Step) [참고링크](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=mmwook94&logNo=221373595289) / [참고링크2](https://iwuooh.com/entry/%EB%8D%B0%EC%9D%B4%ED%84%B0%EB%B2%A0%EC%9D%B4%EC%8A%A4%EC%9D%98-%EC%84%A4%EA%B3%84DataBase-Design%EC%9D%98-%EA%B0%9C%EC%9A%94%EC%99%80-%EB%8B%A8%EA%B3%84)
존재하는 데이터베이스를 위한 새로운 application을 만들거나 새로운 데이터베이스를 만들어내기 위해서는 다음 4개의 stage를 거쳐야한다.
1. Requirement specification and analysis
- 요구사항 분석과 구체화
2. Conceptual design (for easily being transformed into a database implementation)
- 개념 스키마 모델링
- 과정요구사항들을 쉽게 데이베이스에 구현하기위해서 직관적이해가 가능한 형태로 표현하기 위한 단계
- 주로 entity와 그들간의 relation을 표현하기 위해서 entity-relation diagram (ER-Diagram)을 사용하며 ER-Diagram을 이용하여 조직과 사용자들에게 어떠한 데이터들이 중요한지 나타내기위해 사용한다.
3. Logical design (for a data model implemented in a DBMS)
- DBMS에 data model을 구현하기 위한 logical design
- 현실 세계의 데이터를 컴퓨터가 처리할 수 있는 논리적 데이터 구조로 변환
- 논리 데이터 모델링
- 개념적 디자인 과정에서 만들어낸 개념적 스키마를 기반으로 개발에 사용될 DBMS에 적합한 논리적 데이터 모델을 모델링하는 과정 -> ER로 그려낸것들을 테이블로 구현해내는 과정... 이라고 보면 되려나?
- 정규화 과정이 포함됨
4. Physical design (for storing and accessing the database)
- 내가 저장하고자하는 데이터가 어떤 방식으로 저장을 할지, 어떻게 저장장치에 저장할것이며 데이터베이스에 접근을 할지와 같은 물리적 설계를 지칭
- 저장장치에 적합한 저장 레코드와 인덱스 구조와 같은 물리적인 구조를 설계하며 데이터에 접근하기위한 탐색 기법들을 설계
5. Database apllication development(선택)

## 3. Main Characteristics of the database approach
### ★ Main Characteristics of the DB Appproach
(1) "Self-describing" nature of a DB system (자기 서술적 속성을 가지는 DB system): DB system은 DB 그 자체를 의미할 뿐만이 아니라 DB의 structure, types, and contraints 완전한 정의(혹은 서술)을 의미한다.
- Catalog (카탈로그): 특정 DB에 대한 
