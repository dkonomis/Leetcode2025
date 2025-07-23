import pandas as pd

def find_employees(employee: pd.DataFrame) -> pd.DataFrame:
    """
    Problem: 0181 - Employees Earning More Than Their Managers
    
    Find employees who earn more than their managers by joining the employee
    table with itself to compare employee salaries with their manager salaries.
    
    Approach:
    - Self-join the employee table on managerId = id
    - Compare employee salary with manager salary
    - Return only employees who earn more than their managers
    
    Time complexity: O(n) with proper indexing.
    Space complexity: O(n) for the join result.
    """
    # Self-join to get employee and manager information in the same row.
    merged = employee.merge(
        employee,
        left_on='managerId',
        right_on='id',
        suffixes=('_employee', '_manager'),
        how='inner'
    )
    
    # Filter employees who earn more than their managers.
    res = merged[merged['salary_employee'] > merged['salary_manager']]
    
    # Select and rename the employee name column.
    res = res[['name_employee']].rename(columns={'name_employee': 'Employee'})
    
    return res
