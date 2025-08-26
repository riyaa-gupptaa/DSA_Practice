# Write your MySQL query statement below
#Here first we are creating a result set excluding first highest salary i.e max salary
#Again applying max(sal) on this result would fetch the second salary
select max(salary) as SecondHighestSalary from Employee 
where salary not in (select max(salary) from Employee);

#Another Approach
select max(salary) as SecondHighestSalary from Employee
where salary<(select max(salary) from Employee);

#Using Limit and offset
select salary from employee order by salary DESC 
limit 1 offset 1;
