class Solution {
public:
    int subarrayLCM(vector<int>& v, int k) {
        long long ans = 0;
        long long x;
        for (int i = 0; i<v.size(); ++i){
            x = v[i];
            ans += (x == k);
            for (int j = i + 1; j<v.size(); ++j){
                x = lcm(x, v[j]);
                if (x > k){
                    break;
                }
                ans += (x == k);
            }
        }
        return ans;
    }
};
