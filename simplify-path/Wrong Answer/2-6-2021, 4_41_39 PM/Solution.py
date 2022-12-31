// https://leetcode.com/problems/simplify-path

class Solution:
    def simplifyPath(self, path: str) -> str:
        tokens = path.split('/')
        tokens = [x for x in tokens if x != '']
        res = []
        for tok in tokens:
            if tok == '.':
                pass
            elif tok == '..':
                if len(res) == 0:
                    res.append("/")
                else:
                    res.pop()
            else:
                res.append("/" + tok)
        return ''.join(res)