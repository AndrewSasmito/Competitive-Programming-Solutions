class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int dp[1001];
        for (int j = 0; j<=nums.size(); ++j){
            dp[j] = 0;
        }
        dp[1] = k;
        
        for (int i = 2; i<=nums.size(); ++i){
            long long cur = 100000000000, cnt = 0;
            unordered_map <int, int> m;
            
            ++m[nums[i - 1]];
            
            for (int j = i - 1; j>=1; --j){

                //cout << "STATS: " << i << ' ' << j << ' ' << dp[j] << ' ' << cnt << ' ' << cur << '\n';
                cur = min(cur, dp[j] + k + cnt);
                ++m[nums[j - 1]];
                if (m[nums[j - 1]] == 2){
                    ++cnt;
                }
                if (m[nums[j - 1]] > 1){
                    ++cnt;
                }
            }
            cur = min(cur, dp[0] + k + cnt);
            dp[i] = cur;
        }
        

        return dp[nums.size()];
    }
};
