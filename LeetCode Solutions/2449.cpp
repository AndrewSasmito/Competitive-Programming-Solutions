class Solution {
public:
    long long makeSimilar(vector<int>& n1, vector<int>& n2) {
        long long cnt = 0;
        
        vector <int> eve1, odd1, eve2, odd2;
        
        for (int x : n1){
            if (x % 2 == 0){
                eve1.push_back(x);
            }else{
                odd1.push_back(x);
            }
        }
        
        for (int x : n2){
            if (x % 2 == 0){
                eve2.push_back(x);
            }else{
                odd2.push_back(x);
            }
        }
        
        sort (eve1.begin(), eve1.end());
        sort(eve2.begin(), eve2.end());
        
        sort (odd1.begin(), odd1.end());
        sort(odd2.begin(), odd2.end());
        
        for (int i = 0; i<eve1.size(); ++i){
            cnt += abs(eve1[i] - eve2[i]) / 2;
        }
        for (int i = 0; i<odd1.size(); ++i){
            cnt += abs(odd1[i] - odd2[i]) / 2;
        }
        return cnt / 2;
    }
};
