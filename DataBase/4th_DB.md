# 4th_데이타베이스: Chapter 5: The Relational Data Model and Reational Database Constraint
## 1. Relational Model Concept (관계형 모델 개념)
### ☆ 관계형 데이터 모델의 "비공식적"인 정의들
**\[Relation\]**   
- Relation: 집합 개념에 기반을 둔 수학적인 개념
- Relation은 테이블(informal)로 보임 아니면 flat file 형태. -> 이런 realation이 모인 것이 데이터베이스
- Relation은 여러 row(informal)의 집합으로 이루어져 있다. formal하게는 tuple이라고도 부르며 각각의 element들은 entity, realtionship에 대응됨
- Relation은 여러 column header(informal)의 집합으로 이루어짐. formal하게는 attribute라고 부른다.

**\[Key\]**
- Key: 각각의 row는 자신들을 유일하게 구별할 수 있게 해주는 attribute인 key attribute가 존재한다.
- surrogate (or artificial) key: 여러 attribute를 하나로 묶어서 각각의 row를 구분해낼 수도 있음. 하지만 이게 비효율적이라고 느껴져서 row 번호를 사용하여 대신 키로 활용함

### ☆ 관계형 데이터 모델의 "공식적"인 정의들
**\[Relation\]**
- Relation의 Schema: R(A1, A2, ...)로 정의됨 (이때 R은 relation name, A는 Attribute에 해당한다.)
- 속성 순서가 달라지면 해당 realtion의 정의도 달라지기 때문에 서로 다른것이다. (Ex) R1(A1, A2) != R2(A2, A1)
- Degree of the relation R: R의 Attribute 개수에 따라 정의됨
- 각 Attribute는 domain을 가진다. (domain에서 벗어나는 값은 받아들이지 않음)

**\[Tuple\]**
- tuple은 An ordered set of values
- <>로 주로 표시함
- 튜플 각각의 value들은 domain 값을 가짐

**\[Domain\]**
- 도메인은 (D라고 표기): atomic (indivisible)한 values를 가진다.
- data type/data format 형태를 가지거나 name 자체로 가질 수 있음
- attribute의 name이 정확한 "역할"을 지칭하기 때문에 정확한 정의가 될만한 이름을 설정하는것이 좋음.(날짜도 그냥 Date가 아닌 무슨 Date인지.. Birthday? delivery day?)

**\[State\]**
- The relation state: 각 attributes의 도메인의 카테시안 곱으로 구성된 집합의 subset들!
- 이름X번호 = { (윤주영, 1), (윤주영, 2), .... }의 부분집합
- A set of tuple in R ( r(R) = {t1,t2 ...} - t는 tuple)
- all possible combinations of values

### ☆ Relation의 특징들
1. relation의 튜플 사이에 순서는 중요하지 않음
2. relation Schema R 사이에 attribution의 순서는 중요함, self-describing한 형태로 tuple을 정의할 경우에는 순서가 달라도 같은 tuple이라고 볼 수 있음
3. tuple안에 값들은 atomic해야하기 때문에 composite or multi-valued attribution은 존재해서는 안된다. (composite->simple att, multi-valued->separate relation 분리)
4. 각각의 tuple들은 Null value를 가질 수 있음 (Unknown, Not available, Inapplicable)
5. R.A (어떤 relation의 value 지칭 - 예) Student.Name) / t\[A\] or t.A or t\[A1, A2, ... \] (t의 subset)형태로 튜플의 특정 Attribution 값을 참조 가능

## 2. Relational Model Constraints and Relational DataBase Schemas
## ☆ Constraints (제약조건)
- 어떤 값이 database에 들어올 수 있고 어떤 값이 database에 들어오면 안되는지를 구분해낼 수 있다.
- 세가지 카테고리로 나눌 수 있음
  + Inherent or implicit constraints (관계 데이터모델을 채용하면서 발생하는 제약조건)
  + Schema-based or explicit constraints (Data model의 스키마에 의해 발생하는 제약조건)
  + Application-based or semantic constraints (application이나 business 차원에서 발생하는 제약조건 - 데이터모델단계에서는 처리 힘듬)

### 1) Relational Integrity Constrains (앞에서 말한 두번째 제약조건) - 관계 무결성 제약조건
제약조건은 조건으로 모든 relation이 vaild한 상태로 유지되어야한다.   
1. Key constraints (키 제약조건) : Unique constraints (유일 제약조건) -> '키' 속성은 유일값들을 가져야한다.
2. Entity integrity constraints (엔티티 무결성 제약조건) : 키 속성에 대해 Null값을 할당할 수 없다.
3. Referential integrity constrains (참조 무결성 제약조건) : 다른 realtion을 참조할때 지켜야할 제약조건
4. Domain constraints (도메인 제약조건) : 각 value는 attribution의 domain 안에 존재해야한다.

**Key Constraints**   
- relation의 모든 tuple은 구분되어져야함
- 몇개의 속성을 합쳐서 하나의 키로 인식하는 것임 -> 이런 키들을 superkey라고 부름
- relation R의 최소키가 바로 key이다. (즉, superkey중에 최소키가 바로 key)
- key는 superkey지만 superkey가 key인 것은 아니다.
- key로 선택받지 못한 superkey는 candidate key (후보키)라고 한다.

**Entity Integrity Constraints**
- 기본키 속성은 relation에 속하는 모든 튜플의 value에 대해 Null 값을 가지지는 않는다.
- PK(Primary Key)는 각 tuple을 구분하는데 사용하기 때문에 절대 Null을 가지면 안된다.
- PK가 아닌 것은 Null을 가질 수 있음

**Referential Integrity Constraint**
- 두개의 relation 사이에서 생기는 제약조건
- 두개의 relation 사이의 튜플들간의 일관성 유지를 하는데 사용
- Foreign key는 다른 relation으로부터 참조하는 prime key를 지칭하는 말이다.
- 만약 새로운 행이 추가될때, 외래키의 값이 참조되어지는 relation에 PK domain 내에 정의되어야한다. 그렇지 않으면 reject된다.
- 외래키도 기본키와 유사하게 서로 다른 tuple을 구분하는데 사용함 [외래키 개념 참고](https://brunch.co.kr/@dan-kim/26)
- PK는 Null이 되어서는 안되지만 FK는 Null이 될 수 있음 (하지만 이대 FK는 해당 relation에서는 PK가 아닐것임)

**Semantic Integrity ConStraints**
- application semantics에 기반
- 모델을 이용하여 제한할 방법은 없음
- general-purpose constraint specification language에 의해 제약조건을 걸 수 있다.
