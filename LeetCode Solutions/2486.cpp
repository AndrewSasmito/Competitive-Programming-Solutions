class Solution {
public:
    int appendCharacters(string s, string t) {
        int pos = 0;
        for (int i = 0; i<s.size(); ++i){
            if (s[i] == t[pos]){
                ++pos;
            }
        }
        return t.size() - pos;
    }
};
