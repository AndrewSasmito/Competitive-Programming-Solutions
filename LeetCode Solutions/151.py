class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        ans = ""
        n = list(s.split())
        for i in range (len(n) - 1, -1, -1):
            ans += n[i]
            if (i != 0):
                ans += ' '

        return ans
