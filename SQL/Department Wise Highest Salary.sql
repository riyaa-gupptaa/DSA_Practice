-- Common Table Expression (CTE) to find employees with the maximum salary in their department
WITH EmployeesWithMaxSalaryInDepartment AS (
    SELECT
        Department.name AS department,
        -- Department name
        Employee.name AS employee,
        -- Employee name
        Employee.salary,
        -- Employee salary
        -- Calculate the maximum salary within each department using window function
        MAX(Employee.salary) OVER(
            PARTITION BY Employee.departmentId -- Partition by department to get max salary per department
        ) AS max_salary
    FROM
        Employee
        LEFT JOIN Department ON (Employee.departmentId = Department.id) -- Join to get department details
) -- Select employees whose salary matches the maximum salary in their department
SELECT
    department AS Department,
    employee AS Employee,
    salary AS Salary
FROM
    EmployeesWithMaxSalaryInDepartment
WHERE
    salary = max_salary;

-- Filter for employees with the max salary in their department