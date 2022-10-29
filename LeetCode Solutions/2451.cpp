class Solution {
public:
    map <vector<int>, int> m;
    string oddString(vector<string>& v) {
        
        for (string s : v){
            vector <int> x;
            
            for (int i = 1; i<s.size(); ++i){
                x.push_back(s[i] - s[i-1]);
            }
            
            ++m[x];
        }
        
        for (string s : v){
            vector <int> x;
            
            for (int i = 1; i<s.size(); ++i){
                x.push_back(s[i] - s[i-1]);
            }
            
            if (m[x] == 1){
                return s;
            }
        }
        
        return "";
    }
};
