class Solution {
public:
    int passThePillow(int n, int time) {
        bool f = 1;
        int ans = 1;
        for (int i = 0; i<time; ++i){
            if (f == 1){
                if (ans == n){
                    ans = n - 1;
                    f = 0;
                }else{
                    ++ans;
                }
            }else{
                if (ans == 1){
                    ans = 2;
                    f = 1;
                }else{
                    --ans;
                }
            }
        }
        return ans;
    }
};
