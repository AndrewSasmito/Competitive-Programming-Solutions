class Solution {
public:
    int countTime(string s) {
        int cnt1 = 1, cnt2 = 1;
        
        if (s[0] == '?' && s[1] == '?'){
            cnt1 = 24;
        }else if (s[0] == '?'){
            if (s[1] <= '3'){
                cnt1 = 3;
            }else{
                cnt1 = 2;
            }
        }else if (s[1] == '?'){
            if (s[0] == '2'){
                cnt1 = 4;
            }else{
                cnt1 = 10;
            }
        }
        
        if (s[3] == '?' && s[4] == '?'){
            cnt2 = 60;
        }else if (s[3] == '?'){
            cnt2 = 6;
        }else if (s[4] == '?'){
            cnt2 = 10;
        }

        return cnt1 * cnt2;
    }
};
