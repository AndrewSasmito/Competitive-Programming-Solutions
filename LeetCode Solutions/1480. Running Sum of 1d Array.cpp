class Solution {
public:
    vector<int> runningSum(vector<int>& n) {
        vector <int> m;
        m.push_back(n[0]);
        for (int i = 1; i<n.size(); ++i){
            m.push_back(m.back() + n[i]);
        }
        
        return m;
    }
};
