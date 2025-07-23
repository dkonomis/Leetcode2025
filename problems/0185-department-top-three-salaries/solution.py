import pandas as pd

def top_three_salaries(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    """
    Problem: 0185 - Department Top Three Salaries
    
    Find employees who are high earners in each department. A high earner
    has a salary in the top three unique salaries for that department.
    
    Approach:
    - Merge employee and department tables
    - Use dense_rank() to rank salaries within each department
    - Filter for ranks 1, 2, or 3
    - Return with renamed columns
    
    Time complexity: O(n log n) for sorting during ranking.
    Space complexity: O(n) for the merged dataframe and rank column.
    """
    # Merge employee and department tables.
    merged = employee.merge(
        department,
        left_on='departmentId',
        right_on='id',
        suffixes=('_emp', '_dept')
    )
    
    # Rank salaries within each department using dense_rank.
    # Dense rank doesn't skip numbers when there are ties.
    merged['salary_rank'] = merged.groupby('departmentId')['salary'].rank(
        method='dense',
        ascending=False
    )
    
    # Filter for top 3 salary ranks.
    res = merged[merged['salary_rank'] <= 3]
    
    # Select and rename columns.
    res = res[['name_dept', 'name_emp', 'salary']].rename(columns={
        'name_dept': 'Department',
        'name_emp': 'Employee',
        'salary': 'Salary'
    })
    
    return res
