#!/bin/bash

# Problem: 0192 - Word Frequency
#
# Calculate the frequency of each word in words.txt and output
# in descending order of frequency.
#
# Approach:
# - Use tr to convert spaces to newlines (one word per line)
# - Sort the words to group identical words together
# - Use uniq -c to count occurrences of each word
# - Sort by count in descending order
# - Use awk to format output as "word frequency"
#
# Time complexity: O(n log n) for sorting operations.
# Space complexity: O(n) for storing words.

# Read the file and process word frequencies.
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -rn | awk '{print $2 " " $1}'

# Explanation of each command:
# cat words.txt        - Read the file content.
# tr -s ' ' '\n'       - Replace spaces with newlines, squeeze multiple spaces.
# sort                 - Sort words alphabetically to group them.
# uniq -c              - Count unique occurrences (format: "count word").
# sort -rn             - Sort by count numerically in reverse (descending) order.
# awk '{print $2 " " $1}' - Reformat to "word count" instead of "count word".
