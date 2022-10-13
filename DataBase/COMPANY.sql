/*
 	Lab #5-1: Defining the Database Tables for the COMPANY Database
*/

CREATE TABLE DEPARTMENT
(
	Dname		VARCHAR(15)	NOT NULL,
	Dnumber		NUMBER		NOT NULL,
	Mgr_ssn		CHAR(9)		DEFAULT '888665555'	NOT NULL,
	Mgr_start_date	DATE,
	PRIMARY KEY (Dnumber),
	UNIQUE (Dname)
);

CREATE TABLE EMPLOYEE
(
	Fname		VARCHAR(15)	NOT NULL,
	Minit		CHAR,
	Lname		VARCHAR(15),
	Ssn		CHAR(9)		NOT NULL,
	Bdate		DATE,
	Address		VARCHAR(30),
	Sex		CHAR,
	Salary		NUMBER(10,2),
	Super_ssn	CHAR(9),
	Dno		NUMBER	DEFAULT 1 NOT NULL,
	PRIMARY KEY (Ssn)
);

CREATE TABLE DEPT_LOCATION
(
    Dnumber     int     not null,
    Dlocation   varchar(15)     not null,
    primary key (Dnumber, Dlocation),
    foreign key (Dnumber) references department(Dnumber)
);

create table PROJECT
(
    Pname   Varchar(15)     not null,
    Pnumber int             not null,
    Plocation   varchar(15),
    Dnum    int             not null,
    primary key (Pnumber),
    unique (Pname),
    foreign key (Dnum) references Department(Dnumber)
);

create table works_on
(
    Essn    char(9)     not null,
    Pno     int         not null,
    Hours   decimal(3,1),
    primary key (Essn, Pno),
    foreign key (Essn) references EMPLOYEE(Ssn),
    foreign key (Pno) references PROJECT(Pnumber)
);

CREATE TABLE DEPENDENT
(
    Essn    CHAR(9)     not null,
    Dependent_name  varchar(15) not null,
    Sex Char,
    Bdate   Date,
    Relationship    varchar(8),
    primary key (Essn, Dependent_name),
    foreign key (Essn) references employee(Ssn)
);

/*
 	Lab #5-2: Populating the Database
*/

-- Department and Employee
INSERT INTO DEPARTMENT VALUES ('Headquarters', 1, '888665555', TO_DATE('1981-06-19', 'yyyy-mm-dd'));
INSERT INTO EMPLOYEE VALUES ('James', 'E', 'Borg', '888665555', TO_DATE('1937-11-10', 'yyyy-mm-dd'), '450 Stone, Houston, TX', 'M', 55000, NULL, 1);
INSERT INTO DEPARTMENT VALUES ('Administration', 4, '987654321', TO_DATE('1995-01-01', 'yyyy-mm-dd'));
INSERT INTO EMPLOYEE VALUES ('Jennifer', 'S', 'Wallace', '987654321', TO_DATE('1941-06-20', 'yyyy-mm-dd'), '291 Berry, Bellaire, TX', 'F', 43000, '888665555', 4);
INSERT INTO DEPARTMENT VALUES ('Research', 5, '333445555', TO_DATE('1988-05-22', 'yyyy-mm-dd'));
INSERT INTO EMPLOYEE VALUES ('Franklin', 'T', 'Wong', '333445555', TO_DATE('1968-01-19', 'yyyy-mm-dd'), '638 Voss, Houston, TX', 'M', 40000, '888665555', 5);

ALTER TABLE DEPARTMENT ADD FOREIGN KEY (Mgr_ssn) REFERENCES EMPLOYEE(Ssn) ON DELETE SET NULL;
ALTER TABLE EMPLOYEE ADD FOREIGN KEY (Super_ssn) REFERENCES EMPLOYEE(Ssn) ON DELETE SET NULL;
ALTER TABLE EMPLOYEE ADD FOREIGN KEY (Dno) REFERENCES DEPARTMENT(Dnumber) ON DELETE SET NULL;

insert into employee values ('John', 'B', 'Smith', '123456789', to_date('1965-01-09', 'yyyy-mm-dd'),'731 Fondren, Houston, TX', 'M', 30000, '333445555', 5);
insert into employee values ('Alicia', 'J', 'Zelaya', '999887777', to_date('1968-01-19', 'yyyy-mm-dd'), '3321 Castle, Spring, TX', 'F', 25000, '987654321', 4);
insert into employee values ('Remesh', 'K', 'Narayan', '666884444', to_date('1962-09-15', 'yyyy-mm-dd'), '975 Fire Oak, Humble, TX', 'M', 38000, '333445555', 5);
insert into employee values ('Joyce', 'A', 'English', '453453453', to_date('1972-07-31', 'yyyy-mm-dd'), '5631 Rice, Houston, TX', 'F', 25000, '333445555', 5);
insert into employee values ('Ahmad', 'V', 'Jabber', '987987987', to_date('1969-03-29', 'yyyy-mm-dd'), '980 Dalas, Houston, TX', 'M', 25000, '987654321', 4);

-- DEPT_LOCATION
insert into dept_location values (1, 'Houston');
insert into dept_location values (4, 'Stafford');
insert into dept_location values (5, 'Bellaire');
insert into dept_location values (5, 'Sugarland');
insert into dept_location values (5, 'Houston');

-- PROJECT
insert into project values ('ProductX', 1, 'Bellaire', 5);
insert into project values ('ProductY', 2, 'Sugarland', 5);
insert into project values ('ProductZ', 3, 'Houston', 5);
insert into project values ('Computerization', 10, 'Stafford', 4);
insert into project values ('Reorganization', 20, 'Houston', 1);
insert into project values ('Newbenefits', 30, 'Stafford', 4);

-- WORKS_ON
INSERT INTO WORKS_ON VALUES ('123456789', 1, 32.5);
INSERT INTO WORKS_ON VALUES ('123456789', 2, 7.5);
INSERT INTO WORKS_ON VALUES ('666884444', 3, 40.0);
INSERT INTO WORKS_ON VALUES ('453453453', 1, 20.0);
INSERT INTO WORKS_ON VALUES ('453453453', 2, 20.0);
INSERT INTO WORKS_ON VALUES ('333445555', 2, 10.0);
INSERT INTO WORKS_ON VALUES ('333445555', 3, 10.0);
INSERT INTO WORKS_ON VALUES ('333445555', 10, 10.0);
INSERT INTO WORKS_ON VALUES ('333445555', 20, 10.0);
INSERT INTO WORKS_ON VALUES ('999887777', 30, 30.0);
INSERT INTO WORKS_ON VALUES ('999887777', 10, 10.0);
INSERT INTO WORKS_ON VALUES ('987987987', 10, 35.0);
INSERT INTO WORKS_ON VALUES ('987987987', 30, 5.0);
INSERT INTO WORKS_ON VALUES ('987654321', 30, 20.0);
INSERT INTO WORKS_ON VALUES ('987654321', 20, 15.0);
INSERT INTO WORKS_ON VALUES ('888665555', 20, NULL);

-- DEPENDENT
INSERT INTO DEPENDENT VALUES ('333445555', 'Alice', 'F', to_date('1986-04-05', 'yyyy-mm-dd'), 'Daughter');
INSERT INTO DEPENDENT VALUES ('333445555', 'Theodore', 'M', to_date('1983-10-25', 'yyyy-mm-dd'), 'Son');
INSERT INTO DEPENDENT VALUES ('333445555', 'Joy', 'F', to_date('1958-05-03', 'yyyy-mm-dd'), 'Spouse');
INSERT INTO DEPENDENT VALUES ('987654321', 'Abner', 'M', to_date('1942-02-28', 'yyyy-mm-dd'), 'Spouse');
INSERT INTO DEPENDENT VALUES ('123456789', 'Michael', 'M', to_date('1988-01-04', 'yyyy-mm-dd'), 'Son');
INSERT INTO DEPENDENT VALUES ('123456789', 'Alice', 'F', to_date('1988-12-30', 'yyyy-mm-dd'), 'Daughter');
INSERT INTO DEPENDENT VALUES ('123456789', 'Elizabeth', 'F', to_date('1967-05-05', 'yyyy-mm-dd'), 'Spouse');


/*
 	Lab #5-3: Database Querying
*/

-- Q1
SELECT Fname, Lname 
FROM employee, works_on, project
WHERE Dno = 5 AND Salary <= 30000 
AND Pnumber = Pno AND Ssn = Essn -- join condition
AND Pname = 'ProductX' -- selection condition
ORDER BY Lname;

-- Q2
select Dname, Dnumber, Ssn, fname
from department, employee
where Dno = Dnumber 
AND Super_ssn = '987654321'
AND Address LIKE '%TX';

-- Q3
select Lname, B.Pname, D.hours
from employee, works_on C, works_on D, project A, project B
where A.Pnumber = C.Pno
and B.Pnumber = D.Pno
and Ssn = D.Essn
and Ssn = C.Essn
and (A.Pname = 'Reorganization' and C.hours > 1)
order by hours desc;

-- Q4
select DISTINCT Fname, Lname, Hours
from employee, works_on, project
where Ssn = Essn AND Pno = Pnumber
And Pname Like 'Product%' 
and Hours >= 10
Order by hours;

-- Q5
select Lname, Fname, dependent.sex, Relationship
from employee, dependent
where Ssn = Essn
and Super_ssn = '333445555';

/*
 	Lab #5-4: Database Modification - DELETE
*/

commit;
-- D1
delete from dependent
where   essn='123456789' and relationship = 'Spouse';
-- 1 row deleted
rollback;

-- D2
delete from department
where dnumber = 5;
-- Error occur because it can violate reference constraints
rollback;

-- D3
delete from works_on
where Pno = 30 and hours >=50;
-- 0 row deleted
rollback;
commit;

/*
 	Lab #5-5: Database Modification - Update
*/

-- U1
update project p
set p.plocation = 'Daegu'
where Dnum = 4;

select * from project where Dnum = 4;
rollback;

-- U3
update employee e
set address = '80 Daehakro Daegu'
where Dno = 5;

select * from employee where Dno = 5;
rollback;
commit;