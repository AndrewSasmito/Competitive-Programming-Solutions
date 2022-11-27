class Solution(object):
    def pivotInteger(self, n):
        """
        :type n: int
        :rtype: int
        """
        cur = 0
        for i in range(1, n + 1):
            cur += i
            nxt = 0
            for j in range(i, n + 1):
                nxt += j
            if (cur == nxt):
                return i
        return -1
