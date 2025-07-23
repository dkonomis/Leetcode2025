#!/bin/bash

# Problem: 0195 - Tenth Line
# 
# Given a text file file.txt, print just the 10th line of the file.
# If the file contains less than 10 lines, output nothing.
#
# Approach: Use sed to extract exactly the 10th line. The command 10p prints
# line 10, and -n suppresses default output so only line 10 is printed.
#
# Time complexity: O(n). Space complexity: O(1).

# Solution 1: Using sed (most efficient)
# sed -n '10p' file.txt
# -n: suppress automatic printing of pattern space.
# '10p': print only line number 10.
# If line 10 doesn't exist, sed outputs nothing automatically.

# Solution 2: Using awk (alternative approach)
# awk 'NR==10' file.txt
# NR: current record (line) number.
# ==10: condition to match exactly line 10.
# Implicit action is to print the line when condition is true.

# Solution 3: Using head and tail (pipeline approach)
# head -10 file.txt | tail -1
# head -10: get first 10 lines.
# tail -1: get last line from those 10 lines (which is line 10).
# If file has less than 10 lines, this may still output the last line.

sed -n '10p' file.txt
