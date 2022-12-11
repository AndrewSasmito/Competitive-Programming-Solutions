class Solution {
public:
    int maxJump(vector<int>& v) {
        int ans = 0;
        
        for (int i = 2; i<v.size(); i += 2){
            ans = max(ans, v[i] - v[i - 2]);
        }
        if (v.size() % 2 == 1)
            for (int i = v.size() - 4; i>=0; i -= 2){
                ans = max(ans, v[i + 2] - v[i]);
            }
        else
            for (int i = v.size() - 3; i>=0; i -= 2)
                ans = max(ans, v[i + 2] - v[i]);
        
        ans = max(ans, v[v.size() - 1] - v[v.size() - 2]);
        ans = max(ans, v[1] - v[0]);
        return ans;
    }
};
