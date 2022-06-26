class Solution(object):
    def countAsterisks(self, s):
        cnt = 0
        x = s.split('|')
        for i in range(0, len(x), 2):
            for j in range (len(x[i])):
                if (x[i][j] == '*'):
                    cnt += 1
        
        return cnt
        
