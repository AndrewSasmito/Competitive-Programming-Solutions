class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& s, int k) {
        vector <pair<int, int>> v;
        for (int i = 0; i<s.size(); ++i){
            v.push_back(make_pair(s[i][k], i));
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        
        vector<vector<int>> ret;
        
        for (int i = 0; i<v.size(); ++i){
            int x = v[i].second;
            vector <int> vs;
            for (int j = 0; j<s[x].size(); ++j){
                vs.push_back(s[x][j]);
            }
            
            ret.push_back(vs);
        }
        return ret;
    }
};
