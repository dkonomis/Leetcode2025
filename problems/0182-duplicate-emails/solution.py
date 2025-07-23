import pandas as pd

def duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:
    """
    Problem: 0182 - Duplicate Emails
    
    Find all duplicate emails in the Person table. An email is duplicate
    if it appears more than once in the table.
    
    Approach:
    - Group by email and count occurrences
    - Filter emails that appear more than once
    - Return only the email column renamed as 'Email'
    
    Time complexity: O(n) for grouping and counting.
    Space complexity: O(n) for the grouped data.
    """
    # Group by email and count occurrences.
    email_counts = person.groupby('email').size().reset_index(name='count')
    
    # Filter emails that appear more than once.
    duplicates = email_counts[email_counts['count'] > 1]
    
    # Select and rename the email column.
    res = duplicates[['email']].rename(columns={'email': 'Email'})
    
    return res
