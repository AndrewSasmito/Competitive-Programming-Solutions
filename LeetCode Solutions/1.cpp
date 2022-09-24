class Solution {
public:
    unordered_map <int, int> pos;
    vector<int> twoSum(vector<int>& v, int target) {
        vector <int> ans;
        for (int i = 0; i< v.size(); ++i){
            if (pos[target - v[i]] >= 1){
                ans.push_back(i);
                ans.push_back(pos[target - v[i]] - 1);
                return ans;
            }else{
                pos[v[i]] = i + 1;
            }
        }
        return ans;
    }
};
