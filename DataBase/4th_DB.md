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
- A set of tuble in R ( r(R) = {t1,t2 ...} - t는 tuple)
- all possible combinations of values

### ☆ Relation의 특징들
1. relation의 튜플 사이에 순서는 중요하지 않음
2. relation Schema R 사이에 attribution의 순서는 중요함, self-describing한 형태로 tuple을 정의할 경우에는 순서가 달라도 같은 tuple이라고 볼 수 있음
3. tuple안에 값들은 atomic해야하기 때문에 composite or multi-valued attribution은 존재해서는 안된다. (composite->simple att, multi-valued->separate relation 분리)
4. 각각의 tuple들은 Null value를 가질 수 있음 (Unknown, Not available, Inapplicable)
5. R.A (어떤 relation의 value 지칭 - 예) Student.Name) / t\[A\] or t.A or t\[A1, A2, ... \] (t의 subset)형태로 튜플의 특정 Attribution 값을 참조 가능
