# 5th_데이타베이스: Chapter6. Basic SQL (Structural Query Language)
- SQL (Structure Query Language)?   
Tuple calculus로부터 나왔으며 본래 SEQUEL로 불렸음. IBM에서 Experimental Relational database System의 interface로 사용하였다. 이제는 RDBM의 일반적인 언어로 자리잡게 되었음.

## 1. SQL DATA DEFINITION AND DATA TYPES (SQL의 정의와 데이터 타입)
**\[SQL Schema\]**   
- 같은 데이터베이스 내의 구성요소나 테이블을 함께 그룹화하기 위한 개념
- 주로 schema의 이름으로 인식됨 (우리가 앞에서 실습할때 university로 계정을 만들었던 것과 같음 - 그래서 스키마끼리의 동일한 이름은 허용되지 않는다.)
- 스키마를 가진 사람이나 계정을 지칭하는 authorization identifier (e.g. 'Joshua')와 스키마내의 element를 위한 descriptors (e.g. 'CREATE TABLE ...')가 포함된다.
- Schema elements (constructs): Table(relation), constraints, views, domains, and other constructs.
- SQL의 각 statment는 ;(세미콜론)으로 끝내야함.

```SQL
  # 모든 유저가 스키마나 스키마 element를 만들 권한을 부여받지는 않음
  CREATE SCHEMA 스키마이름 AUTHORIZATION 계정이름
```

**\[CREATE TABLE\]**   
- 속성과 그것들의 타입 (정의역) 그리고 제약조건을 정의해야한다.
- Relation 정의를 할때는 Attribute 먼저 정의
- 각각의 Attribute 이름과 data type 정의
- 제약조건은 Unique나 Not null 같은 것들임

```SQL
  CREATE TABLE 스키마이름.테이블이름 (explicit)
  CREATE TABLE 테이블이름 (implicit)
```
- Table을 생성할때 외래키에 의한 순환참조 문제(아직 테이블이 만들어지지 않았는데 스스로가 가진 키를 참조해야하는 상황)가 발생할 수 있음
- 위의 순환참조 문제를 ALTER TABLE 문으로 해결할 수 있다.

**\[Attribute Data Types and Domains in SQL\]**   
- 'Numeric' data types
    + 정수: INTEGER, INT, SMALLINT
    + 실수: FLOAT, REAL, DOUBLE, PRECISION
    + 포맷숫자: DECIMAL(i,j) = DEC(i,j) = NUMBERIC(i,j) ~> i는 표현하고싶은 자릿수, j는 소숫점 자리수
    + NUMBER는 DECIMAL을 대체할 수 있다.
- 'Character' data types
    + 고정길이: CHAR(n), CHARACTER(n) ~> 최대 n길이로 적을 수 있고 안적은 만큼 공백문자로 채움
    + 변동길이: VARCHAR(n), CHAR VARYING(n), CHARACTER VARING(n) -> 얘들은 최대 4KB 저장 가능.. 더 큰 문자열은 CLOB(최대 저장 크기)를 사용하면 됨
- 'Bit-String' data types
    + 고정길이: BIT(n)
    + 변동길이: BIT VARYING(n) -> 위와 마찬가지로 더 큰 비트문자열은 BLOB(최대 저장 크기)를 사용
- 'Boolean' data type
    + TRUE / FALSE
    + NULL
- 'Date' data type
    + Year, Month, and Day를 적절히 사용하여 YYYY-MM-DD 같은 형식으로 사용한다.
    + 오라클로 하면 to_date(날짜, 형식)이 DATE의 역할을 대신함
- 'Time' data type
    + Hour, Minute, and Second를 사용하여 HH:MM:SS 같은 형식을 사용한다.
    + 예를 들어 TIME '09:12:47'
- 'Timestamp' data type
    + DATE와 TIME 필드의 짬뽕형태 ~ 초단위에 최대 6자까지의 소수점이 붙을 수 있음
    + 예를 들어 TIMESTAMP '2014-09-27 09:12:47.648302'
- 'INTERVAL' data type
    + date, time, timestamp 들의 간격을 저장할 수 있음
    + 예를 들어 INTERVAL '40' MONTH = INTERVAL '3-4' YEAR TO MONTH 처럼 작성
- Domain
    + 특정 타입을 지정하기 보다는 어떤 데이터 타입을 선언할 수 있음
    + column의 타입에 대해 더 구체적 명시가 필요할때
    + 스키마가 더 읽기 쉬워진다.
    + CREATE DOMAIN SSN_TYPE AS CHAR(9); -> SSN_TYPE이 CHAR(9)와 동일시하게 기능한다. 약간 C언어의 typedef 같은 느낌임
- Type
    + 사실상 객체 역할
    + 이론상으론 지원안하지만 실제 praticle하게 지원하는 형태
    + user defined type을 만들어낼 수 있음 -> C언어의 구조체 느낌
    + 예를 들어서 아래와 같은 형태로 사용가능하다.
```SQL
    CREATE TYPE type_demo as object
    (
        customer_id     NUMBER(6);
        customer_last_name  VARCHAR2(20)
    );
```

## 2. SPECIFYING CONSTRAINTS IN SQL (SQL에서 제약조건 설정하기)
앞에서 공부한 대표적인 3가지 constraints를 실제로 sql로 구현해볼것임.   
Key constraint -> PRIMARY KEY / Entity constraint -> NOT NULL / Referential integrity constraints -> FOREIGN KEY

**\[Specifying "Attribute" Constraints\]**   
- Default \<value\> clause
- NULL : NULL 허용하지 않으려면 NOT NULL를 사용하면 된다.
- CHECK clause : 예를 들어 Dnumber INT NOT NULL CHECK (Dnumber > 0 and Dnumber < 10) 과 같이 CHECK 뒤에 Attribution의 제약조건 설정 가능

**\[Specifying "Key" Constraints\]**
- PRIMARY KEY clause : 하나 혹은 그 이상으로 기본키 설정 가능 E.g) Dnumber INT PRIMARY KEY / PRIMARY KEY(State, Number) 과 같이 사용가능하다.
- UNIQUE clause : 후보키이자 2차키로서 사용 E.g) Dnumber VARCHAR2 UNIQUE / UNIQUE(State, Number)

**\[Referential Integrity\]**
- FOREIGN KEY clause : 기본적으로 데이터가 violation한 상황은 update(insert/delete)를 reject 시킴
- reject 대신에 SET NULL (아예 NULL하게 만들기) 과 CASCADE option을 사용 가능하다. SET DEFAULT도 있지만 Oracle은 지원하지않음

## 3. BASIC RETRIEVAL QUERIES IN SQL (일반적인 SQL에서의 검색 쿼리)
```SQL
  -- Basic SQL Query Block
  SELECT  <attribute list>
  FROM    <relation list>
  [WHERE  <condition>] -- 선택적 조건
  [GROUP BY <attribute list>] -- 결과에서 subgroup을 만들어내기위해 사용한다.
  [HAVING   <condition>] -- group 중에 조건을 걸어둘때 group에 대한 조건 설정
  [ORDER BY <attribute list> [DESC]; -- 정렬기준 설정, 오름차순 기본
```

**\[Ambiguous Attribution Names\]**   
Query문을 작성하다보면 서로 다른 relation에 있는 동일한 Attribution을 가져와야한다거나 같은 relation을 두번 참고하면서 이름이 겹칠 수 있음   
\-> 그때 사용하는게 (1) Fully-qualified 방식 그리고 (2) Aliasing and Renaming 방식이 있다.
