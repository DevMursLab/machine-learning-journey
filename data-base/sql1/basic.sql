#create database company1;
use company1;
#create table
create table student(
roll_no int,
name varchar(30),
age int
);
#insert  tables
insert into student
values
(101,"adam",12),
(102,"bob",14);
select * from student;
create database Employes;
use  Employes;

create table Employes_data(
 EmpID INT,
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    Department VARCHAR(50),
    Salary INT,
    HireDate DATE
);
INSERT INTO Employes_data(EmpID, FirstName, LastName, Department, Salary, HireDate) VALUES
(101, 'Alice', 'Johnson', 'IT', 6500, '2020-03-15'),
(102, 'Mark', 'Rivera', 'HR', 4800, '2019-07-22'),
(103, 'Sophia', 'Lee', 'Finance', 7200, '2021-01-10'),
(104, 'Daniel', 'Kim', 'IT', 5800, '2018-11-05'),
(105, 'Emma', 'Brown', 'Marketing', 5300, '2022-04-18'),
(106, 'Liam', 'Patel', 'Finance', 6900, '2020-09-29'),
(107, 'Olivia', 'Garcia', 'HR', 4600, '2017-06-30'),
(108, 'Noah', 'Thompson', 'IT', 7500, '2023-02-12'),
(109, 'Ava', 'Martinez', 'Marketing', 5100, '2019-12-02'),
(110, 'Ethan', 'Davis', 'Finance', 8000, '2016-05-14');

select * from Employes_data;
-- select * from Employes_data order by salary desc
SELECT Department, SUM(Salary) AS TotalSalary  # avg,min,max  alll  aggregate function
FROM  Employes_data
GROUP BY Department;

SELECT Department, SUM(Salary) AS TotalSalary
FROM Employes_data
GROUP BY Department
HAVING SUM(Salary) > 12000;


select Department,count(EmpID)as emp_count
FROM Employes_data
GROUP BY Department
having emp_count>3;


SELECT COUNT(Department) 
FROM Employes_data;