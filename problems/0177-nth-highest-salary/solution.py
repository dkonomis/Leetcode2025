import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    """
    0177 - Nth Highest Salary
    
    Find the Nth highest distinct salary from Employee table.
    Return None if there are less than N distinct salaries or if N is invalid.
    
    Approach:
    - Use pandas rank() with dense ranking to handle duplicates elegantly
    - Filter for rows where rank equals N
    - rank() naturally handles edge cases (negative N returns empty result)
    - Extract salary value or default to None if no match
    
    Time complexity: O(n log n) due to ranking.
    Space complexity: O(n) for deduplicated data.
    """
    # Remove duplicate salaries and add dense ranking.
    unique_df = employee.drop_duplicates(subset='salary')
    unique_df['rank'] = unique_df['salary'].rank(method='dense', ascending=False)
    
    # Filter for the Nth highest salary.
    nth_salary_rows = unique_df[unique_df['rank'] == N]
    
    # Extract salary value or None if no match found.
    salary_value = nth_salary_rows['salary'].iloc[0] if len(nth_salary_rows) > 0 else None
    
    # Create result with dynamic column name.
    column_name = f"getNthHighestSalary({N})"
    res = pd.DataFrame({column_name: [salary_value]})
    
    return res
