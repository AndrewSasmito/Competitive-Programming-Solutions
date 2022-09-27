class Solution {
public:
    unordered_set <int> s;
    unordered_map <int, bool> m;
    vector<vector<int>> findDifference(vector<int>& v1, vector<int>& v2) {
        vector <vector<int>> ans;
        for (int x : v1)
            s.insert(x);
        
        for (int x : v2){
            if (s.find(x) != s.end()){
                s.erase(x);
                m[x] = 1;
            }
        }
        
        vector <int> v;
        
        for (int x : v1){
            if (m[x] == 0){
                m[x] = 1;
                v.push_back(x);
            }
        }
        ans.push_back(v);
        v.clear();
        
        for (int x : v2){
            if (m[x] == 0){
                m[x] = 1;
                v.push_back(x);
            }
        }
        ans.push_back(v);
        return ans;
    }
};
