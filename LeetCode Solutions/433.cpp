class Solution {
public:
    set <int> st;
    void calc(string s, string t, vector<string>& v, int i){
        if (s == t){
            st.insert(i);
            return;
        }else if (i >= 8){
            return;
        }else{
            for (string x : v){
                int cnt = 0;

                for (int i = 0; i<s.size(); ++i){
                    if (s[i] != x[i]){
                        ++cnt;
                    }
                }
                if (cnt == 1){
                    calc(x, t, v, i + 1);
                }
            }
        }
    }

    int minMutation(string start, string end, vector<string>& bank) {
        calc(start, end, bank, 0);
        if (st.size() == 0){
            return -1;
        }else{
            return *st.begin();
        }   
    }
};
