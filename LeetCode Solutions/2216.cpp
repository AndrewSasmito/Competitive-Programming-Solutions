class Solution {
public:
    int minDeletion(vector<int>& v) {
        int ans = 0;
        for (int i = 1; i<v.size(); ++i){
            if (v[i] == v[i-1]){
                ++ans;
            }else{
                ++i;
            }
        }
        if ((v.size() - ans) % 2 == 1){
            ++ans;
        }
        return ans;
    }
};
