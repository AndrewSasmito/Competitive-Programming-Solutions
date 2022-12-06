class Solution {
public:
    int dp[10001];
    int jump(vector<int>& nums) {
        for (int i = 1; i<nums.size(); ++i){
            dp[i] = 10000;
        }
        for (int i = 0; i<nums.size(); ++i){
            for (int j = 1; j<=nums[i] && i + j < nums.size(); ++j){
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
        return dp[nums.size() - 1];
    }
};
