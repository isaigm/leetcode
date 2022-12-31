// https://leetcode.com/problems/jewels-and-stones

class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        return len(re.findall("["+J+"]", S))