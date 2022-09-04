class Solution {
public:
    bool checkDistances(string s, vector<int>& dis) {
        bool f, st;
        for (int i = 0; i<s.size(); ++i){
            f = 1;
            st = 1;
            
            if (dis[s[i] - 'a'] + i + 1 < s.size()){
                if (s[dis[s[i] - 'a'] + i + 1] != s[i]){
                    f = 0;
                }
            }else{
                f = 0;
            }
            if (i - dis[s[i] - 'a'] - 1 >= 0){
                if (s[i - dis[s[i] - 'a'] - 1] != s[i]){
                    st = 0;
                }
            }else{
                st = 0;
            }

            
            if (f == 0 && st == 0){
                return 0;
            }
        }
        return 1;
    }
};
