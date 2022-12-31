// https://leetcode.com/problems/regular-expression-matching

import re
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        pattern = '^' + p + '$'
        return len(re.findall(pattern, s)) > 0