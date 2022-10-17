/*
	Lab#6 Write Advanced SQL statements
*/

-- Lab#6-1: Aggregates
-- 1)
SELECT Dname, count(*) AS COUT
FROM   EMPLOYEE, DEPARTMENT
WHERE Dnumber = Dno
AND Dnumber In (SELECT Dno
                FROM EMPLOYEE
                GROUP BY Dno
                HAVING AVG(Salary) >= 20000)
GROUP BY Dname
ORDER by COUT DESC;

-- 2)
SELECT Dnumber, Dname, count(*)
FROM   EMPLOYEE, DEPARTMENT
WHERE Dnumber = Dno
AND SEX = 'F'
AND Salary >= 20000
group by Dnumber, Dname
order by Dnumber;


-- Lab#6-2: Not Exist
-- 1)
SELECT E.Fname, E.Lname, E.Salary
FROM EMPLOYEE E
WHERE NOT EXISTS((SELECT Dnumber
                    FROM DEPARTMENT
                    WHERE Dno=1)
                    MINUS
                    (SELECT Pno
                     FROM WORKS_ON W
                     WHERE E.Ssn = W.Essn))
ORDER BY E.Salary DESC;

-- 2)
SELECT D.Dnumber, D.Dname, E.Fname, E.Lname
FROM DEPARTMENT D, EMPLOYEE E
WHERE D.Mgr_ssn = E.Ssn
AND NOT EXISTS(SELECT *
                FROM DEPENDENT DT
                WHERE DT.Essn = D.Mgr_ssn);


-- Lab#6-3: Nested Query
-- 1)
select Fname, Lname
from employee
where Dno In (SELECT DISTINCT Dno
                	FROM EMPLOYEE
                	WHERE Salary IN (SELECT MAX(Salary)
                                		FROM EMPLOYEE));
-- 2)
SELECT Fname, Lname
FROM Employee
where Super_Ssn IN(SELECT Ssn
                    FROM Employee
                    WHERE Super_Ssn = '888665555');

-- 3)
Select Fname, Lname
from employee
where Salary >= ALL(SELECT DISTINCT SALARY
                	FROM EMPLOYEE
                	WHERE Salary IN (SELECT MIN(Salary)+5000
                                		FROM EMPLOYEE));

-- Lab#6-4: View
-- 1)
CREATE VIEW DEPT_SUMMARY (D, C, Total_s, Avg_s) AS
 SELECT Dno, COUNT(*), Sum(Salary), ROUND(AVG(Salary), 1)
 FROM   EMPLOYEE
 GROUP BY Dno;

-- 2)
SELECT *
FROM DEPT_SUMMARY WHERE D = 4;

/* OUTPUT:
D          C    TOTAL_S      AVG_S
---------- ---------- ---------- ----------
	4          3      93000      31000
*/

-- 3)
SELECT D, C
FROM DEPT_SUMMARY
WHERE TOTAL_S BETWEEN 50000 AND 100000;

/* OUTPUT:
D          C
---------- ----------
         1          1
         4          3
*/

-- 4)
SELECT D, AVG_S
FROM DEPT_SUMMARY
WHERE C > (SELECT C FROM DEPT_SUMMARY WHERE D = 1)
ORDER BY AVG_S DESC;

/* OUTPUT:
         D      AVG_S
---------- ----------
         5      33250
         4      31000
*/

-- 5)
UPDATE DEPT_SUMMARY
SET D = 3
WHERE D = 1;
/* OUTPUT:
SQL 오류: ORA-01732: 뷰에 대한 데이터 조작이 부적합합니다
01732. 00000 -  "data manipulation operation not legal on this view"
*/

-- 6)
DELETE FROM DEPT_SUMMARY
WHERE C >= 1;
/* OUTPUT:
SQL 오류: ORA-01732: 뷰에 대한 데이터 조작이 부적합합니다
01732. 00000 -  "data manipulation operation not legal on this view"
*/

-- Lab#6-5: Trigger
CREATE TRIGGER SALARY_VIOLATION
BEFORE INSERT OR UPDATE OF Salary ON EMPLOYEE
FOR EACH ROW
WHEN (NEW.Salary > 80000)
    DECLARE
        DIFF INTEGER;
    BEGIN
        DIFF := abs(:New.Salary - :Old.Salary);
        DBMS_OUTPUT.PUT_LINE('Old salary: '||:OLD.Salary);
        DBMS_OUTPUT.PUT_LINE('[ALTER] New salary: '||:NEW.Salary);
        DBMS_OUTPUT.PUT_LINE('Salary difference: '||Diff);
    END;

/* Memo: 위의 것을 실행하고 아래 스크립트 실행! ALTER과 함께하면 오류 일으킴
ALTER TRIGGER SALARY_VIOLATION ENABLE;
SET SERVEROUTPUT ON;

-- university대신 company에서 작업했습니다.
UPDATE Company.EMPLOYEE
SET Salary = Salary*2
WHERE Ssn = '888665555';

ROLLBACK;

DROP TRIGGER Company.SALARY_VIOLATION;
*/