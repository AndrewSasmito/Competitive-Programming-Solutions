class Solution {
public:
    int longestContinuousSubstring(string s) {
        int cnt = 1, ans = 1;
        for (int i = 1; i < s.size(); ++i){
            if (s[i - 1] - 'a' + 1 == s[i] - 'a'){
                
                ++cnt;
            }else{
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};
