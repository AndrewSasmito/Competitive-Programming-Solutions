class Solution {
public:
    unordered_map <int, int> m;
    void sortColors(vector<int>& v) {
        int cnt = 0;
        for (int x : v){
            ++m[x];
        }


        for (int i = 0; i < v.size(); ++i){
            while (m[cnt] == 0){
                ++cnt;
            }

            v[i] = cnt;
            --m[cnt];
        }
    }
};
