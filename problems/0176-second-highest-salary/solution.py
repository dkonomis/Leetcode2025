import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    """
    0176 - Second Highest Salary
    
    Find the second highest distinct salary from Employee table.
    Return None if there is no second highest salary.
    
    Approach:
    - Get unique salaries to handle duplicates
    - Sort in descending order to get highest salaries first  
    - Check if at least 2 unique salaries exist
    - Return second highest or None based on availability
    - Wrap result in DataFrame with proper column name
    
    Time complexity: O(n log n) due to sorting.
    Space complexity: O(n) for unique salaries.
    """
    # Get unique salaries and sort in descending order.
    unique_salaries = employee['salary'].drop_duplicates().sort_values(ascending=False)
    
    # Check if we have at least 2 unique salaries.
    if len(unique_salaries) < 2:
        # Return None if no second highest salary exists.
        second_highest = None
    else:
        # Get the second highest salary (index 1 after sorting).
        second_highest = unique_salaries.iloc[1]
    
    # Return result as DataFrame with required column name.
    return pd.DataFrame({'SecondHighestSalary': [second_highest]})
