class Solution {
public:
    int dp[31];
    int calc(int n){
        if (dp[n] != -1){
            return dp[n];
        }else{
            return dp[n] = calc(n - 1) + calc(n - 2);
        }
    }

    int fib(int n) {
        for (int i = 0; i<31; ++i){
            dp[i] = -1;
        }
        dp[0] = 0, dp[1] = 1;
        return calc(n);
    }
};
