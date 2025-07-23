import pandas as pd

def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    """
    0178 - Rank Scores
    
    Rank all scores from highest to lowest using dense ranking.
    Ties get the same rank, next rank is consecutive (no gaps).
    
    Approach:
    - Use pandas rank() with method='dense' for consecutive ranking
    - Sort by score in descending order for output
    - Return only score and rank columns
    - Convert rank to int for clean output
    
    Time complexity: O(n log n) due to sorting.
    Space complexity: O(n) for the ranking column.
    """
    # Add dense ranking column - highest score gets rank 1.
    scores['rank'] = scores['score'].rank(method='dense', ascending=False).astype(int)
    
    # Sort by score in descending order.
    scores = scores.sort_values(by='score', ascending=False)
    
    # Return only the required columns.
    return scores[['score', 'rank']]
