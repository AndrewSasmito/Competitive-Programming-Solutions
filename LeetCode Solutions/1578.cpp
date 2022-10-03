class Solution {
public:
    multiset <int> st;
    int minCost(string s, vector<int>& v) {
        int ans = 0;
        st.insert(v[0]);

        for (int i = 1; i<v.size(); ++i){
            if (s[i] == s[i-1]){
                st.insert(v[i]);
            }else{
                while (st.size() > 1){
                    ans += *st.begin();
                    st.erase(st.begin());
                }
                st.clear();
                st.insert(v[i]);
            }
        }
        while (st.size() > 1){
            ans += *st.begin();
            st.erase(st.begin());
        }
        return ans;
    }
};
