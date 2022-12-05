class Solution {
public:
    long long dividePlayers(vector<int>& v) {
        sort(v.begin(), v.end());
        long long ret = v[0] * v.back();
        int cur = v[0] + v.back();
        
        for (int i = 1; i<v.size()/2; ++i){
            if (cur != v[i] + v[v.size() - i - 1])
                return -1;
            
            ret += v[i] * v[v.size() - i - 1];
        }
        
        return ret;
    }
};
