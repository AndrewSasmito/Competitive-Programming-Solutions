class Solution {
public:
    int ans1 = 0, ans2 = -1, mn = 1000000, dp[100], cur[100];
    unordered_set <int> st;
    string ans = "";

    bool valid(){
        for (int x : st){
            if (dp[x] > cur[x]){
                return 0;
            }
        }
        return 1;
    }

    string minWindow(string s, string t) {


        for (int i = 0; i<t.size(); ++i){
            ++dp[t[i] - 'A'];
            st.insert(t[i] - 'A');
        }

        int l = 0, r = -1;
        bool f;
        while (true){

            if (l == s.size() - 1 && r == s.size() - 1){
                break;
            }else if (r == s.size() - 1){
                --cur[s[l] - 'A'];
                ++l;
                if (valid() == 1){
                    if (mn > r - l){
                        mn = r - l, ans1 = r, ans2 = l;
                    }
                }else{
                    break;
                }
            }else if (l == r || valid() == 0){
                ++r;
                ++cur[s[r] - 'A'];
                
                if (valid() == 1){
                    if (mn > r - l){
                        mn = r - l, ans1 = r, ans2 = l;
                    }
                }
            }else{
                --cur[s[l] - 'A'];
                ++l;

                if (valid() == 1){
                    if (mn > r - l){
                        mn = r - l, ans1 = r, ans2 = l;
                    }
                }
            }
        }
        if (ans2 == -1){
            return ans;
        }
        for (ans2; ans2 <= ans1; ++ans2){
            ans += s[ans2];
        }
        return ans;
    }
};
