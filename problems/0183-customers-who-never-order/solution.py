import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    """
    Problem: 0183 - Customers Who Never Order
    
    Find all customers who have never placed an order by identifying
    customer IDs that don't appear in the orders table.
    
    Approach:
    - Use isin() to check which customer IDs are not in the orders table
    - Filter customers whose IDs are not in the orders customerId column
    - Return only the name column renamed as 'Customers'
    
    Time complexity: O(n + m) where n is customers size and m is orders size.
    Space complexity: O(m) for storing the set of customer IDs who ordered.
    """
    # Find customers whose ID is not in the orders table.
    customers_who_never_order = customers[~customers['id'].isin(orders['customerId'])]
    
    # Select and rename the name column.
    res = customers_who_never_order[['name']].rename(columns={'name': 'Customers'})
    
    return res
