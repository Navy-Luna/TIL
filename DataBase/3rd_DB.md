# 3nd_week_데이타베이스: Chapter3. Data Modeling Using the Entity-Relationship (ER) Model

## 1. Overview of Database Design Process
### Database Application (데이터베이스 응용 프로그램)   
- 특정 데이터베이스와 질의나 업데이트를 실행할 수 있는 프로그램들이다. (ex) 은행 데이터베이스 응용 프로그램
- application design과 database design 2개의 main 활동들이 필요하다.
  + application design: 프로그램을 만드는데 집중하며 DB에 접근하기위한 인터페이스 설계를 어떻게 할지가 중점임. software engineering의 한 부분
  + database design: 앞에서 배운 4 Steps를 거치며 데이터베이스를 디자인

### A Simplified Overview of Database Design Process
1. 요구사항 명세화 및 분석: 기능적인 요구+어떤 데이터가 필요한지
2. Conceptual 디자인: 개념 스키마 설계 -> 보통 ER Model을 사용하여 설계
3. Logical 디자인: 로지컬(=개념적) 스키마 설계
4. Physical 디자인: 내부스키마 설계 - 내부 저장소 구조, 파일 형식, 인덱스, 경로 접속 방식 등을 설계

------------------------------------------------

## 2. Entity Types, Entity Sets, Attributions, and keys

### Concepts: Entities & Attributiones(+Attribution Type)
- Entity-Relationship (ER) 모델은 데이터를 묘사할 때: Entitieds, relationships, attributes 개념 사용 (얘들을 정확히 아는게 중요)
- Entity는 하나의 객체나 대상이고 Attribution은 그들이 가질 수 있는 속성이라고 보면 된다. (Entity: 사람1, Attribution: 전화번호 010.. / 이름: ..)
  + Simple (atomic) Attribution: 값을 하나만 가질 수 있는 속성 (ex) SEX ~ 남자이면서 여자는 안됨. 남자거나 여자거나
  + Composite Attribution: 여러 개의 구성요소로 이루어진 속성 (ex) Name (First Name, Last Name)
  + Multi-valued: 값을 여러개 가질 수 있는 속성 (ex) 대학생 개체의 속성인 전공은 복수전공이라면 컴퓨터공학, 영어영문학 과 같이 값을 여러개 가질 수 있다.
- Stored attribute VS Derived Attribute: 이미 저장되어 있는 속성 VS 저장되어 있는것에서 파생된 속성 (Ex) Birth_date VS Age
- Complex attribute: Composite Attribute + Multi-values


### Entity Type and Entity Sets
- Entity type (intension): 같은 속성을 가진 entity 집합 (ex) Employee안에 각각의 entity들은 (name, age, Salary) 속성 정보를 가짐 ~ 자바 클래스 느낌.
- Entity set (extension): entity type을 똑같이 가지는 entity의 collection (ex) 김사원 (김xx, 24, 100000), 구사원 (구oo, 25, 200000) 이 두명 묶어서 entity set ~ 자바 인스턴스 집합.
- Entity Type의 key Attribution: value가 유일하게 하나만 가지는 attribute가 존재할수 있다. key attribute는 entity type에 2개 이상 존재할 수 있다.
- value set: 각 attribute가 가질 수 있는 value set -> 이 set을 벗어나는 것은 reject 되도록 함.

------------------------------------------------

## 3. Relationship types, relationship sets, roles, and structural constranints
- A relationship: 두개 이상의 entities끼리 특별한 관계를 가지는것
- 관계타입(relationship type): n개의 entities 사이에 연관성의 타입 (같은 유형의 관계 특성을 하나로 묶어서 type형태로 정의한것) -> 관계유형의 차수는 몇개의 entities가 참여한지에 따라 다르다.
- 관계집합(relationship instance): 관계유형의 특성을 가지는 관계 인스턴스들의 집합체라고 보면 된다.

### Role Name (역할 이름)
- 관계 인스턴스에 참여하고 있는 entity type에 속하는 entity에 역할을 부여하는 것임.
- 보통 참여하는 entities의 이름들로 역할을 이름을 정의함.

### Recursive Relationship (or Self-Referencing Relationship)
같은 entity 타입에 있는 entity와 관련이 있는것으로 관계자는 같은 entity typo이지만 다른 역할을 수행. 같은 employee 라는 entity type을 가지더라도 employee내의 entity 끼리 상하 관계가 존재할 수 있듯이.

### Structural Constraints on Binary Relationship Types (이진 관계 유형의 구조적 제약 조건)
관계성은 2가지 제약조건을 명시함으로서 표현할 수 있다. [참고자료](https://victorydntmd.tistory.com/126)
#### 1. Cardinality ratio (카디널리티 비율 제약조건) ~ 몇 대 몇으로 참여하느냐와 관련된 제약조건
각 관계 인스턴스에 최대로 참여할 수 있는 엔티티의 수. 한 개체가 얼마나 많은 다른 개체와 관계를 가질 수 있는지를 명시. 1:1 / 1:N / M:N (N, M은 최대가 없다)
#### 2. Participation constraint (참여 제약조건)
- 두 entity type에 대하여 한 개체가 다른 개체에 의존하는지 여부를 나타낸다. 관계 인스턴스에 참여하는 최소 숫자를 명시하게 된다.
  + Total participation (existence dependency) : ER에서 double line으로 표시 - 전체가 참여 해야함
  + Partial participation (default) : ER에서 line 하나로 표시 - 굳이 모두가 참여할 필요 없음

## 4. Weak Entity Type
- 자기 자신을 위한 key attribute를 가지지 않는 데이터 타입으로 다른 entity type에 의존하는 경향이 있음 그래서 child (or subordinate) entity type이라고도 한다.
- 약한 엔티티 타입의 엔티티는 다른 엔티티(부모 엔티티)에 의존해야 존재할 수 있다.
- weak entity type은 partial key (다른 entity와 구분할 수 있게 해주는 속성 집합) + particular (parent) entity의 조합으로 identity를 획득한다.

