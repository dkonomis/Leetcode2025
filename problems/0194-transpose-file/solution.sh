#!/bin/bash

# Problem: 0194 - Transpose File
# 
# Given a text file file.txt, transpose its content where each row has the same
# number of columns and fields are separated by space characters.
#
# Approach: Use awk to read all fields into a 2D array, then output by columns.
# For each field position i, concatenate all values from that position across rows.
#
# Time complexity: O(n * m). Space complexity: O(n * m).

# AWK script breakdown:
# For each line (NR = record number, NF = number of fields):
# - Loop through each field position (1 to NF).
# - If this is the first row (NR == 1), initialize array with first field.
# - Otherwise, append current field to existing array element with space.
# In END block, print each array element as a separate line.
# This transforms rows into columns by grouping fields by position.

awk '{
    for (i = 1; i <= NF; i++) {
        if (NR == 1) {
            arr[i] = $i
        } else {
            arr[i] = arr[i] " " $i
        }
    }
}
END {
    for (i = 1; i <= NF; i++) {
        print arr[i]
    }
}' file.txt
