class Solution {
public:
    vector<int> findErrorNums(vector<int>& v) {
        vector <int> ans;
        unordered_map <int, int> m;
        for (int x : v){
            ++m[x];
            if (m[x] == 2){
                ans.push_back(x);
            }
        }
        for (int i = 1; i<=v.size(); ++i){
            if (m[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
