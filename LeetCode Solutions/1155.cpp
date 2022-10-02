class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[31][1001];
    int numRollsToTarget(int n, int m, int target) {
        
        for (int i = 0; i<n; ++i){
            for (int j = 0; j <= target; ++j){
                dp[i][j] = 0;
            }
        }

        for (int i = 1; i<=m; ++i){
            dp[0][i] = 1;
        }

        for (int i = 1; i < n; ++i){
            for (int j = 1; j<=target; ++j){
                for (int k = 1; k <= m; ++k){
                    if (j < k){
                        break;
                    }

                    if (dp[i - 1][j - k] > 0){
                        dp[i][j] += dp[i - 1][j - k];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }

        return dp[n - 1][target];
    }
};
