class Solution {
public:
    unordered_map <int, int> m;
    set <int> s;
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& v1, vector<vector<int>>& v2) {
        vector<vector<int>> ans;
        for (auto x : v1){
            s.insert(x[0]);
            
            m[x[0]] += x[1];
        }
        
         for (auto x : v2){
            s.insert(x[0]);
            
            m[x[0]] += x[1];
        }
        
        for (auto x : s){
            vector <int> cnt;
            cnt.push_back(x);
            cnt.push_back(m[x]);
            
            ans.push_back(cnt);
        }
        return ans;
    }
};
