class Solution(object):
    def convertTemperature(self, c):
        """
        :type celsius: float
        :rtype: List[float]
        """
        ans = []
        
        ans.append(c + + 273.15)
        ans.append(c * 1.80 + 32.00)
        return ans
        
