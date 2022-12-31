// https://leetcode.com/problems/valid-phone-numbers

# Read from the file file.txt and output all valid phone numbers to stdout.
#!/bin/bash 
result=$(cat file.txt | grep -E "([[:digit:]]{3}-[[:digit:]]{3}-[[:digit:]]{4})|(\([[:digit:]]{3}\)\s[[:digit:]]{3}-[[:digit:]]{4})")
echo "$result"
