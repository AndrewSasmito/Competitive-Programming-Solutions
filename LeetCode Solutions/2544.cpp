class Solution {
public:
    int alternateDigitSum(int n) {
        int tot = 0, f = 1;
        string s = to_string(n);
        
        for (int i = 0; i<s.size(); ++i){
            tot += ((s[i] - '0') * f);
            f *= -1;
        }
        
        return tot;
    }
};
