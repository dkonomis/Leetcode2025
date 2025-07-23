#!/bin/bash

# Problem: 0193 - Valid Phone Numbers
# 
# Given a text file with phone numbers (one per line), write a one-liner bash script
# to print all valid phone numbers matching: (xxx) xxx-xxxx or xxx-xxx-xxxx.
#
# Approach: Use grep with regex to match both valid formats. The pattern uses
# alternation to match either format with exact digit requirements.
#
# Time complexity: O(n). Space complexity: O(1).

# Regex breakdown: ^(\([0-9]{3}\) [0-9]{3}-[0-9]{4}|[0-9]{3}-[0-9]{3}-[0-9]{4})$
# ^ - Start of line anchor (ensures pattern matches from beginning).
# $ - End of line anchor (ensures pattern matches to the end).
# ( ... | ... ) - Grouping with alternation (OR operator).
# Left side matches format: (xxx) xxx-xxxx.
# Right side matches format: xxx-xxx-xxxx.
# 
# Left Pattern: \([0-9]{3}\) [0-9]{3}-[0-9]{4}
# \( - Literal opening parenthesis (escaped because parenthesis has special meaning).
# [0-9]{3} - Exactly 3 digits (character class for digits 0-9).
# \) - Literal closing parenthesis (escaped).
# (space) - Literal space character.
# [0-9]{3} - Exactly 3 digits.
# - - Literal hyphen.
# [0-9]{4} - Exactly 4 digits.
#
# Right Pattern: [0-9]{3}-[0-9]{3}-[0-9]{4}
# [0-9]{3} - Exactly 3 digits.
# - - Literal hyphen.
# [0-9]{3} - Exactly 3 digits.
# - - Literal hyphen.
# [0-9]{4} - Exactly 4 digits.

grep -E "^(\([0-9]{3}\) [0-9]{3}-[0-9]{4})$|^([0-9]{3}-[0-9]{3}-[0-9]{4})$" file.txt
