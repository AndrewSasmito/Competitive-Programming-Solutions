class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector <string> ans;
        for (string s : queries){
            for (string x : dictionary){
                int cnt = 0;
                bool f = 0;
                
                for (int i = 0; i<s.size(); ++i){
                    cnt += (s[i] != x[i]);
                    if (cnt == 3){
                        f = 1;
                        break;
                    }
                }
                
                if (f == 0){
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};
