import pandas as pd

def delete_duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:
    """
    Problem: 0196 - Delete Duplicate Emails
    
    Given a DataFrame with id and email columns, delete all duplicate emails
    keeping only the one with the smallest id. Modify the DataFrame in place.
    
    Approach: Sort by id to ensure smallest id comes first, then drop duplicates
    based on email column keeping the first occurrence (smallest id).
    
    Time complexity: O(n log n). Space complexity: O(1).
    """
    # Sort by id to ensure smallest id appears first for each email.
    person.sort_values('id', inplace=True)
    
    # Drop duplicates based on email, keeping first occurrence (smallest id).
    person.drop_duplicates(subset=['email'], keep='first', inplace=True)

    return
