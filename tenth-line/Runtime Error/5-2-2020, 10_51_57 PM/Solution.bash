// https://leetcode.com/problems/tenth-line

# Read from the file file.txt and output the tenth line to stdout.
cat -e file.txt | head -n 10 | tail -n 1    