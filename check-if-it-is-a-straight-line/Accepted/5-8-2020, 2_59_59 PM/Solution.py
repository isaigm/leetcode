// https://leetcode.com/problems/check-if-it-is-a-straight-line

class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        ms = []
        not_zero_div = []
        for idx in range(len(coordinates) - 1):
            p1 = coordinates[idx]
            p2 = coordinates[idx + 1]
            try:
                m = (p1[1] - p2[1]) / (p1[0] - p2[0])
                ms.append(m)
                not_zero_div.append(True)
            except:
                not_zero_div.append(False)
        return len(set(ms)) == 1 and all(not_zero_div)