CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT BEGIN RETURN (
    # Write your MySQL query statement below.
    Select
        salary
    from
(
            Select
                salary,
                DENSE_RANK() OVER(
                    ORDER BY
                        salary desc
                ) as r
            from
                Employee
        ) AS ranked_salaries
    WHERE
        r = N
    LIMIT
        1
);

END