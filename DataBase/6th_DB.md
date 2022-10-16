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
