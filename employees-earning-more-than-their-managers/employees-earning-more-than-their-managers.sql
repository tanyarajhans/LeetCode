# Write your MySQL query statement below
SELECT a.NAME as Employee FROM EMPLOYEE as a, EMPLOYEE as b WHERE a.ManagerId=b.Id and a.SALARY>b.salary;