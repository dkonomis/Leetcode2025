# 0193. Valid Phone Numbers

**Difficulty**: Easy  
**Link**: LeetCode 193

---

Given a text file `file.txt` that contains a list of phone numbers (one per line), write a one-liner bash script to print all valid phone numbers.

You may assume that a valid phone number must appear in one of the following two formats: `(xxx) xxx-xxxx` or `xxx-xxx-xxxx`. (`x` means a digit)

You may also assume each line in the text file must not contain leading or trailing white spaces.

**Example:**

Assume that `file.txt` has the following content:

    987-123-4567
    123 456 7890
    (123) 456-7890

Your script should output the following valid phone numbers:

    987-123-4567
    (123) 456-7890
