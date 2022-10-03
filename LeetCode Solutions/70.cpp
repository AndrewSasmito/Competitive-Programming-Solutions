class Solution {
public:
    int dp[46];
    int climbStairs(int n) {
        dp[0] = 1;
        for (int i = 1; i<=n; ++i){
            for (int j = 1; j<=2; ++j){
                if (i < j){
                    break;
                }

                dp[i] += dp[i - j];
            }
        }
        return dp[n];
    }
};
