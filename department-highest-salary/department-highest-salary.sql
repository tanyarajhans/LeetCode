# Write your MySQL query statement below
select d.name as 'Department',E.NAME AS 'Employee',e.salary
from department d,employee e
where d.id = e.departmentId
and e.salary = (select max(e1.salary) from employee e1 where e1.departmentId = d.id)