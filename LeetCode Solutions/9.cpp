class Solution {
public:
    string s;
    bool isPalindrome(int x) {
        s = to_string(x);
        
        for (int i = 0; i<s.size() / 2; ++i){
            if (s[i] != s[s.size() - i - 1]){
                return 0;
            }
        }
        return 1;
    }
};
