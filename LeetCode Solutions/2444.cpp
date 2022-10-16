class Solution {
public:
    long long countSubarrays(vector<int>& v, int mn, int mx) {
        long long ret = 0;
        
        int mns, mxs, left = 0;
        bool f = 0, s = 0;
        for (int i = 0; i<v.size(); ++i){
            if (v[i] == mn){
                mns = i;
                f = 1;
            }if (v[i] == mx){
                mxs = i;
                s = 1;
            }if (v[i] < mn || v[i] > mx){
                f = 0;
                s = 0;
                left = i + 1;
            }
            
            if (f == 1 && s == 1){
                ret += min(mns, mxs) - left + 1;
            }
        }
        
        return ret;
    }
};
