// https://leetcode.com/problems/largest-time-for-given-digits

class Solution:
    def largestTimeFromDigits(self, A: [int]) -> str:
        fd = max(list(filter(lambda x: x <= 2, A + [-1])))
        if fd == -1: return ""
        A.remove(fd)
        sd = max(list(filter(lambda x: x <= 3, A + [-1])))
        if sd == -1: return ""
        A.remove(sd)
        td = max(list(filter(lambda x: x <= 5, A + [-1])))
        if td == -1: return ""
        ld = A[0]
        return str(fd) + str(sd) + ":" + str(td) + str(ld)
        