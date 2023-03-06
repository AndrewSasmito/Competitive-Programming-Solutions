class Solution {
public:
    const int MOD = 1e9 + 7;
    int ans[1101];
    int waysToReachTarget(int target, vector<vector<int>>& v) {

        ans[0] = 1;
        for (int i = 0; i<v.size(); ++i){
            for (int j = target; j - v[i][1] >= 0; --j){
                if (ans[j - v[i][1]] > 0){
                    for (int k = 0; k<v[i][0]; ++k){
                        if (j + (v[i][1] * k) > target){
                            break;
                        }
                        ans[j + (v[i][1] * k)] += ans[j - v[i][1]];
                        ans[j + (v[i][1] * k)] %= MOD;
                    }
                }
            }
        }
        
        

        return ans[target];
    }
};
