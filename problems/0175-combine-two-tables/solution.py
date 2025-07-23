import pandas as pd

def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    """
    0175 - Combine Two Tables
    
    Combine Person and Address tables to report firstName, lastName, city, and state.
    Include all people even if they don't have addresses (use NULL for missing data).
    
    Approach:
    - Use pandas merge with 'left' join to keep all people from Person table
    - Join on 'personId' column which exists in both tables
    - Left join ensures people without addresses are included with NaN values
    - Select only required columns in correct order
    
    Time complexity: O(n + m) where n, m are table sizes.
    Space complexity: O(n + m) for result DataFrame.
    """
    # Perform left join on personId to include all people.
    # Left join keeps all rows from person (left table) and matches from address (right table).
    result = person.merge(address, on='personId', how='left')
    
    # Select only the required columns in the specified order.
    # NaN values will automatically appear for people without addresses.
    return result[['firstName', 'lastName', 'city', 'state']]
