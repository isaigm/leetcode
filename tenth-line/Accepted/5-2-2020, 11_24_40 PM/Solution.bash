// https://leetcode.com/problems/tenth-line

# Read from the file file.txt and output the tenth line to stdout.
lines=$(cat file.txt | wc -l)
if [ $lines -gt 9 ]
then
	res=$(cat file.txt | head -n 10 | tail -n 1)
	echo "$res"
else
	printf ""
fi
