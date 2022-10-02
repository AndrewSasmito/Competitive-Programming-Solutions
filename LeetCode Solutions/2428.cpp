class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        long long cnt = 0, cur;
        for (int i = 0; i < grid.size() - 2; ++i){
            for (int j = 0; j < grid[i].size() - 2; ++j){
                cur = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
                cnt = max(cnt, cur);
            }
        }
        return cnt;
    }
};
