class Solution {
public:
    unordered_map <char, int> m1;
    unordered_map <char, int> m2;
    unordered_set <char> st;
    int ans = 1000000000;
    int rearrangeCharacters(string s, string target) {
        for (char x : s){
            ++m1[x];
        }
        
        for (char x : target){
            ++m2[x];
            st.insert(x);
        }
        
        for (char x : st){
            ans = min(ans, m1[x] / m2[x]);
        }
        return ans;
    }
};
