// https://leetcode.com/problems/tenth-line

# Read from the file file.txt and output the tenth line to stdout.
lines=$(cat lines.txt | wc -l)
if [ $lines -gt 9 ]
then
        cat lines.txt | head -n 10 | tail -n 1
else
        echo " "
fi

