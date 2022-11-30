class Solution {
public:
    set <int> s, st;
    unordered_map <int, int> m;
    bool uniqueOccurrences(vector<int>& arr) {
        for (int x : arr){
            s.insert(x);
            ++m[x];
        }

        for (int x : s){
            st.insert(m[x]);
        }

        return st.size() == s.size();
    }
};
