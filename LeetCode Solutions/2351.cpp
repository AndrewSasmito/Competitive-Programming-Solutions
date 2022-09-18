class Solution {
public:
    char repeatedCharacter(string s) {
        char c = 'A';
        map <char, int> m;
        for (int i = 0; i < s.size(); ++i){
            ++m[s[i]];
            if (m[s[i]] > 1){
                return c = s[i];
            }
        }
        //Has to be here because it isnt guaranteed to return :(
        return c;
    }
};
