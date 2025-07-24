import pandas as pd

def trips_and_users(trips: pd.DataFrame, users: pd.DataFrame) -> pd.DataFrame:
    """
    Problem: 0262 - Trips and Users
    
    Calculate cancellation rate for unbanned users between dates.
    1. Filter unbanned users (clients and drivers).
    2. Join trips with users twice for client and driver.
    3. Filter date range and calculate cancellation rate.
    4. Round to 2 decimal places.
    
    Time complexity: O(n log n) for joins and groupby.
    Space complexity: O(n) for intermediate dataframes.
    """
    # Get unbanned users.
    unbanned_users = users[users['banned'] == 'No']['users_id'].tolist()
    
    # Filter trips with unbanned clients and drivers.
    valid_trips = trips[
        (trips['client_id'].isin(unbanned_users)) & 
        (trips['driver_id'].isin(unbanned_users))
    ]
    
    # Filter date range.
    valid_trips = valid_trips[
        (valid_trips['request_at'] >= '2013-10-01') & 
        (valid_trips['request_at'] <= '2013-10-03')
    ]
    
    # Calculate cancellation rate by day.
    res = valid_trips.groupby('request_at').agg({
        'status': [
            lambda x: (x.str.startswith('cancelled')).sum(),  # Cancelled count.
            'count'  # Total count.
        ]
    })
    
    # Flatten column names.
    res.columns = ['cancelled', 'total']
    
    # Calculate cancellation rate.
    res['Cancellation Rate'] = (res['cancelled'] / res['total']).round(2)
    
    # Reset index and rename columns.
    res = res.reset_index()
    res = res.rename(columns={'request_at': 'Day'})[['Day', 'Cancellation Rate']]
    
    return res
