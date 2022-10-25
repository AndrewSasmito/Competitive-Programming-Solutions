class Solution {
public:
    int ans = 0, dp[(1<<16)];

    bool check(string s, string t){
        unordered_map <char, int> m;

        for (char c : s){
            ++m[c];
            if (m[c] == 2){
                return 0;
            }
        }

        for (char c : t){
            ++m[c];
            if (m[c] == 2){
                return 0;
            }
        }
        return 1;
    }

    void calc(string s, int mask, int i, vector<string>& v){
        if (i == v.size()){
            int cur = s.size();
            ans = max(ans, cur);
            dp[mask] = 1;
            return;
        }else if (dp[mask] == 1){
            return;
        }

        dp[mask] = 1;

        for (int i = 0; i<v.size(); ++i){
            if ((mask&(1<<i)) == 0){
                int cur = s.size();

                if (check(s, v[i]) == 0){
                    ans = max(ans, cur);
                }else{
                    calc(s + v[i], mask|(1<<i), i + 1, v);
                }
            }
        }
    }

    int maxLength(vector<string>& arr) {
        calc("", 0, 0, arr);

        return ans;
    }
};
