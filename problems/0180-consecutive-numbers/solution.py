import pandas as pd

def consecutive_numbers(logs: pd.DataFrame) -> pd.DataFrame:
    """
    Problem: 0180 - Consecutive Numbers
    
    Find all numbers that appear at least three times consecutively in the logs table.
    We need to check if a number appears in at least 3 consecutive rows based on id order.
    
    Approach:
    - Sort by id to ensure consecutive order
    - Use shift to compare current row with previous and next rows
    - Check where all three consecutive values are the same
    - Return distinct numbers that meet this criteria
    
    Time complexity: O(n log n) due to sorting.
    Space complexity: O(n) for the shifted columns.
    """
    # Sort by id to ensure consecutive order.
    logs = logs.sort_values('id')
    
    # Check if current num equals previous num and next num.
    logs['prev_num'] = logs['num'].shift(1)
    logs['next_num'] = logs['num'].shift(-1)
    
    # Find rows where all three consecutive numbers are the same.
    consecutive_mask = (logs['num'] == logs['prev_num']) & (logs['num'] == logs['next_num'])
    
    # Get distinct numbers that appear consecutively.
    res = pd.DataFrame({
        'ConsecutiveNums': logs[consecutive_mask]['num'].unique()
    })
    
    return res
