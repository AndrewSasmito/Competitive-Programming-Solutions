class Solution {
public:
    int minimumRecolors(string s, int k) {
        int tot, bcnt = 0;
        for (int i = 0; i < k; ++i){
            if (s[i] == 'B'){
                ++bcnt;
            }
        }
        
        tot = bcnt;
        cout << "HERE\n";
        for (int i = k; i < s.size(); ++i){
            if (s[i] == 'B'){
                ++bcnt;
            }if (s[i - k] == 'B'){
                --bcnt;
            }
            tot = max(bcnt, tot);
        }
        
        return k - tot;
    }
};
