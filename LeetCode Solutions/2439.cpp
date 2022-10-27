class Solution {
public:
    #define ll long long
    int minimizeArrayValue(vector<int>& v) {
        long long av = 0, tot = 0;
        
        for (int i = 0; i<v.size(); ++i){
            tot += v[i];
            av = max(av, (tot + i) / (i + 1));
        }
        return av;
    }
};
