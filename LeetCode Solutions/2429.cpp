class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = 0, ans = 0, dp[32];
        
        for (int i = 0; i < 31; ++i){
           if ((num2 & (1<<i)) == 0){
             ++cnt;
           }
        }
        cnt = 31 - cnt;

        for (int i = 0; i<31; ++i){
            if ((num1 & (1<<i)) == 0){
                dp[i] = 0;
            }else{
                dp[i] = 1;
            }
        }
        
        for (int i = 30; i >= 0; --i){
            if (dp[i] == 1 && cnt > 0){
                dp[i] = 0;
                ans |= (1<<i);
                --cnt;
            }
        }
        for (int i = 0; i < 31; ++i){
            if (cnt > 0 && (ans & (1<<i)) == 0){
                ans |= (1<<i);
                --cnt;
            }
        }
        return ans;
    }
};
