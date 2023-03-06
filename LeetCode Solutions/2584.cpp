class Solution {
public:
    int findValidSplit(vector<int>& v) {
        //prime factorization & two pointers
    
        unordered_set <int> s1, s2;
        unordered_map <int, int> m;
        for (int i = 0; i<v.size(); ++i){
            int nw = v[i];
            for (int j = 2; j * j <= nw; ++j){
                while (nw % j == 0){
                    nw /= j;
                    s2.insert(j);
                    ++m[j];
                }
            }
            
            if (nw != 1){
                s2.insert(nw);
                ++m[nw];
            }
        }
        
        for (int i = 0; i<v.size() - 1; ++i){
            int nw = v[i];
            for (int j = 2; j * j <= nw; ++j){
                while (nw % j == 0){
                    nw /= j;
                    s1.insert(j);
                    --m[j];
                    if (m[j] == 0){
                        s2.erase(s2.find(j));
                    }
                }
            }
            if (nw != 1){
                s1.insert(nw);
                --m[nw];
                if (m[nw] == 0){
                    s2.erase(s2.find(nw));
                }
            }
            bool f = 0;
            for (auto x : s1){
                if (m[x] > 0){
                    f = 1;
                    break;
                }
            }
            if (f == 0){
                return i;
            }
        }
        return -1;
    }
};
