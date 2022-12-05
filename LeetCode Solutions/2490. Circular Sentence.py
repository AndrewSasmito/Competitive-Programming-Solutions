class Solution(object):
    def isCircularSentence(self, sentence):
        """
        :type sentence: str
        :rtype: bool
        """
        
        s = list(sentence.split())
        
        for i in range(1, len(s)):
            if (s[i - 1][-1] != s[i][0]):
                return 0
        
        if (s[-1][-1] != s[0][0]):
            return 0
        return 1
        
