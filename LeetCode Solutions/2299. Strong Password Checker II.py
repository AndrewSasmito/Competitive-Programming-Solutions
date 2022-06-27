class Solution(object):
    def strongPasswordCheckerII(self, s):
        if (len(s) < 8):
            return 0
        l = 0
        u = 0
        d = 0
        spec = 0
        st = "!@#$%^&*()-+"
        for i in range (0, len(s)):
            if (i > 0):
                if (s[i-1] == s[i]):
                    print(s[i])
                    print(s[i-1])
                    print(i)
                    return 0
            
            if (s[i].isdigit()):
                d = 1
            elif (s[i].isupper()):
                u = 1
            elif (s[i].islower()):
                l = 1
            elif s[i] in st:
                spec = 1
            elif (s[i] == '"'):
                spec = 1
        
        print(l)
        print(u)
        print(d)
        print(spec)
        if (l == 1 and u == 1 and d == 1 and spec == 1):
            return 1
        else:
            return 0

        
