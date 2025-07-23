import pandas as pd

def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    """
    Problem: 0184 - Department Highest Salary
    
    Find employees who have the highest salary in each department.
    Multiple employees can have the same highest salary in a department.
    
    Approach:
    - Merge employee and department tables
    - Use transform('max') to get max salary for each department
    - Filter employees whose salary equals the department max
    - Return with renamed columns
    
    Time complexity: O(n log n) for the merge operation.
    Space complexity: O(n) for the merged dataframe.
    """
    # Merge employee and department tables on departmentId.
    merged = employee.merge(
        department, 
        left_on='departmentId', 
        right_on='id',
        suffixes=('_emp', '_dept')
    )
    
    # Get max salary for each department using transform.
    merged['max_salary'] = merged.groupby('departmentId')['salary'].transform('max')
    
    # Filter employees who have the max salary in their department.
    res = merged[merged['salary'] == merged['max_salary']]
    
    # Select and rename columns.
    res = res[['name_dept', 'name_emp', 'salary']].rename(columns={
        'name_dept': 'Department',
        'name_emp': 'Employee', 
        'salary': 'Salary'
    })
    
    return res
