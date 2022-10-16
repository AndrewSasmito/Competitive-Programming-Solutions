class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& v) {
        vector <int> ans, temp;
        const long long MOD = 1e9 + 7;
        long long cur;
        
        for (int i = 0; i<31; ++i){
            if (n & (1 << i)){
                temp.push_back(1 << i);
            }
        }
        
        for (int i = 0; i<v.size(); ++i){
            cur = 1;
            for (int j = v[i][0]; j <= v[i][1]; ++j){
                cur *= temp[j];
                cur %= MOD;
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
