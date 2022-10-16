# 6th_week_데이타베이스: Complex Queries, Triggers, Views, and Schema Modification
## 1. MORE COMPLEX SQL RETRIEVAL QUERIES (더 복잡한 검색 쿼리)
**추가적인 기능을 사용하여서 유저는 더 복잡한 질의문을 구현하여 원하는 데이터를 얻을 수 있음**   
- Nested Queries (중첩 질의문)
- Joined tables (Natural Join)
- Outer joins in the FROM caluse
- Views (Derived Tables), Assertions, Triggers
- Aggregate functions (집계 함수)
- Grouping

### Nested Query (중첩 질의)
**서브쿼리란?**   
- [Oracle: SQL 서브쿼리](https://mjn5027.tistory.com/m/51)
- sub query 혹은 inner query라고 불린다.
- 하나의 쿼리 문장 내에 포함된 또 하나의 쿼리 문장.
- 비교연산자의 오른쪽에 기술해야 하고 반드시 괄호 안에 넣어야 함.
- 메인 쿼리가 실행되기 이전에 한 번만 실행됨.
- SELECT, FROM, WHERE 어디에 속하냐에 따라 다르게 작동한다.

**중첩 쿼리**   
- 중첩 서브 쿼리라고도 불리며 WHERE문 안에 포함되어있음

☆ 다양한 Set/Multiset 비교연산자   
- IN
  + IN 연산자는 조건의 범위를 지정하는 데 사용된다. 값은 콤마( , )로 구분하여 괄호 내에 묶으며, 이 값 중에서 하나 이상과 일치하면 조건에 맞는 것으로 평가된다.
  + 보통 앞의 값이 뒤에 set에 포함되냐를 따지고 포함되는것만 가져오는 것으로 보임.
  + 특정 값 여러개를 선택하는 경우에 사용
  + OR로 대체하여 사용해 볼 수 있음

- ALL
  + 메인쿼리의 비교조건이 서브쿼리의 검색결과와 모든 값이 일치하면 참
  + > 나 < 와 같은 것을 사용하여 모든 값들과 비교할 수 있게 해줌

- Exist
  + Exist의 결과값은 True / False로만 나옴
  + In과는 다르게 메인 쿼리의 내용이 sub query에 포함되어있음 -> 차이점 파악해두자
  + 메인의 내용을 들고가서 subquery의 조건에 맞는게 하나라도 있으면 True를 반환함.
  + 약간 메인의 조건에 부합하는 애들 쫄랭졸랭 들고가서 서브 쿼리에 조건 만족하는게 하나라도 있나? 찾아보는 느낌?
  + And나 OR로 묶여 있으면 둘다 속해있거나 하나라도 속해 있어야 결과가 나옴.

- Not Exist
  + Exist와는 반대로 메인 쿼리의 내용을 들고가서 서브쿼리의 검색 결과내에 없으면 그 결과를 출력한다.
  + [Exist와 NOT EXIST설명01](https://gent.tistory.com/m/278) & [Exist와 NOT EXIST설명02](https://what-am-i.tistory.com/m/86?category=1011285)


### Different Types of JOINed Tables in SQL (SQL의 서로 다른 타입의 Join Table)
**Natured Join**   
- 같은 이름과 같은 타입을 가진 열에 대해서 두 테이블에 대해 조인함
- 이름이 다르다면 조인되지 않으므로 조인하고 싶다면 이름을 AS를 이용해 바꿔줄 수도 있음
- From 절에 붙여서 사용한다.
- [SQL Natural Join](https://the-underwater.tistory.com/m/26)

**Inner Join**   
- 기준 테이블과 조인 테이블 모두에 데이터가 있어야 조회된다.
- 일반적인 조인의 기본적인 타입
- 조인은 기준 테이블(employee), 조인 테이블(department)에 서로 대응되는 조인 컬럼에 해당하는 값이 모두 존재하는 경우에만 데이터가 조회된다.
- FROM 절에 붙여서 사용한다.
- [Inner Join VS Natural Join](https://pakker.tistory.com/m/115)
```SQL
   SELECT Fname, Lname, Address
   FROM   (EMPLOYEE (INNER) JOIN DEPARTMENT ON Dno = Dnumber)
   WHERE  Dname = 'Research';
```

**Outer Join**   
- Left/Right/Full Outer Join으로 나뉜다.
- 기준 테이블을 왼쪽 혹은 오른쪽으로 두고 하나로 합친다.
- 없는 데이터에 대해서는 NULL로 표시한다.
```SQL
  SELECT E.Lname AS Supervisee_Name, S.Lname AS Supervisor_Name
  FROM Employee E LEFT OUTER JOIN EMPLOYEE S ON E.Super_ssn = S.Ssn;
```

[Inner Join과 Outer Join 참고](https://gent.tistory.com/m/376)

### Aggregate Functions in SQL (SQL에서의 집계함수)
- 그룹별로 단일 결과 보여줄라고 하는 것임
- COUNT, SUM, MAX, MIN, AVG 있음
- GROUP BY 로 그룹 묶고 할 수도 있고 Having으로 그룹 조건 줄 수 있음
- 집계함수는 Having이나 Select 절에 사용할 수 있다.
```SQL
-- COUNT를 사용할때, 특정 label이름을 넣고 사용할 경우에는 null은 빼고 센다.
  SELECT COUNT(*), SUM(Salary), MAX(Salary), MIN(Salary), AVG(Salary)
  FROM   EMPLOYEE;
```

**Group by**
- 같은 그룹끼리 묶어서 표시해준다.
- aggregation function이랑 같이 써줘야 되는듯!
- select 절에 group하는 label이 반드시 포함되어 있어야한다. -> select에서 집계함수 제외하고의 label을 보여주려면 그것들을 group by에도 써주는것 잊지 말자!
- 2개 이상이면 2개에 매칭되는거만 찾는 것임.
- Having으로 보여주는 group 제한할 수 있음


