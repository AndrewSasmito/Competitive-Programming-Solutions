class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[100001];
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        
        dp[0] = 1;
        for (int i = 1; i<=high; ++i){
            if (zero <= i){
                dp[i] += dp[i - zero];
                dp[i] %= MOD;
            }
            if (one <= i){
                dp[i] += dp[i - one];
                dp[i] %= MOD;
            }
            
            if (low <= i){
                ans += dp[i];
                ans %= MOD;
            }
        }
        
        return ans;
    }
};
