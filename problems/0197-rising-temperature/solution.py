import pandas as pd

def rising_temperature(weather: pd.DataFrame) -> pd.DataFrame:
    """
    Problem: 0197 - Rising Temperature
    
    Given a weather DataFrame with id, recordDate, and temperature columns,
    find all dates with higher temperatures compared to the previous day.
    
    Approach: Self-merge on consecutive dates to compare temperatures directly
    without sorting. More efficient than sort-then-shift approach.
    
    Time complexity: O(n). Space complexity: O(n).
    """
    # Create yesterday's date for each record.
    weather['yesterday'] = weather['recordDate'] - pd.Timedelta(days=1)
    
    # Self-merge to find records where today's date matches yesterday's date from another record.
    merged = weather.merge(
        weather[['recordDate', 'temperature']], 
        left_on='yesterday', 
        right_on='recordDate', 
        suffixes=('_today', '_yesterday')
    )
    
    # Filter rows where today's temperature is higher than yesterday's.
    rising_mask = merged['temperature_today'] > merged['temperature_yesterday']
    
    # Return only the id column for rising temperature days.
    res = merged[rising_mask][['id']]
    
    return res
