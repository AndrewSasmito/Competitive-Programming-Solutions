class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0, tmp;
        
        for (string x : strs){
            bool f = 0;
            for (int i = 0; i<x.size(); ++i){
                if (!('0' <= x[i] && x[i] <= '9')){
                    f = 1;
                    break;
                }
            }
            
            if (f == 0){
                tmp = stoi(x);
                ans = max(ans, tmp);
            }else{
                tmp = x.size();
                ans = max(ans, tmp);
            }
        }
        
        return ans;
    }
};
