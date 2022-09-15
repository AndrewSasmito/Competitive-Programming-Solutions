class Solution {
public:
    int partitionString(string s) {
        string cur = "";
        int cnt = 1;
        unordered_set <char> st;
           
        for (int i = 0; i<s.size(); ++i){
            cur += s[i];
            st.insert(s[i]);

            if (cur.size() > st.size()){
                ++cnt;
                cur = s[i];
                st.clear();
                st.insert(s[i]);
            }
        }
        return cnt;
    }
};
