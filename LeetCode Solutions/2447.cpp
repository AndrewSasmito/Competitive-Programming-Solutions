class Solution {
public:
    int subarrayGCD(vector<int>& v, int k) {
        int cnt = 0, ans = 0;
        
        for (int i = 0; i<v.size(); ++i){
            for (int j = i; j<v.size(); ++j){
                if (j == i){
                    cnt = v[j];
                }else{
                    cnt = __gcd(cnt, v[j]);
                }
                
                if (cnt == k){
                    ++ans;
                }
            }
        }
        return ans;
    }
};
