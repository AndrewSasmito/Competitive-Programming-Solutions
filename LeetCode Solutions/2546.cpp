class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        bool f = 0, st = 0, ff = 0, ss = 0;
        for (int i = 0; i<s.size(); ++i){
            if (s[i] == '1'){
                f = 1;
            }else{
                st = 1;
            }
            
            if (target[i] == '1'){
                ff = 1;
            }else{
                ss = 1;
            }
        }
        //cout << f << ' ' << st << ' ' << ff << ' ' << ss << '\n';
        if (f == 1 && st == 1 && ff == 1 && ss == 1){
            //cout << 1 << '\n';
            //All
            return 1;
        }else if (f == 1 && ss == 1 && ff == 1){
            //cout << 2 << '\n';
            //1111
            //101011
            return 1;
        }else if (st == 1 && ss == 1 && ff == 0 && f == 0){
            //cout << 3 << '\n';
            //0000000
            //000000
            return 1;
        }else if (f == 1 && ff == 1 && ss == 0){
            //cout << 4 << '\n';
            //111111
            //111111
            return 1;
        }else{
            return 0;
        }
    }
};
