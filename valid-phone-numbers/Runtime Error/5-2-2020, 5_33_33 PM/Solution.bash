// https://leetcode.com/problems/valid-phone-numbers

#!/bin/bash 
result=$(cat file.txt | grep -E "([[:digit:]]{3}-[[:digit:]]{3}-[[:digit:]]{4})|([[:digit:]]?\([[:digit:]]{3}\)\s[[:digit:]]{3}-[[:digit:]]{4})")
echo "$result"
