class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& v) {
        int dis[s.size() + 1], cnt = 0;
        for (int i = 0; i < s.size(); ++i){
            dis[i] = 0;
        }
        for (int i = 0; i<v.size(); ++i){
            if (v[i][2] == 1){
                ++dis[v[i][0]];
                --dis[v[i][1] + 1];
            }else{
                --dis[v[i][0]];
                ++dis[v[i][1] + 1];                
            }
        }
        
        for (int i = 0; i<s.size(); ++i){
            cnt += dis[i];
            
            while (cnt < 0){
                cnt += 26;
            }
            cnt %= 26;
            
            s[i] = (char)(((s[i] - 'a' + cnt) % 26) + 'a');
        }
        return s;
    }
};
