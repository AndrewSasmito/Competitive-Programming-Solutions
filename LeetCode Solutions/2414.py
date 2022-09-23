class Solution(object):
    def longestContinuousSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt = 1
        ans = 1
        for i in range(1, len(s)):
            if (ord(s[i-1]) - 95 == ord(s[i]) - 96):
                cnt += 1
            else:
                ans = max(ans, cnt)
                cnt = 1
        ans = max(ans, cnt)
        return ans
