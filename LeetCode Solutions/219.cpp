class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& v, int k) {
        unordered_map <int, int> m;

        for (int i = 0; i<v.size(); ++i){
            if (m[v[i]] != 0 && (i + 1) - m[v[i]] <= k){
                return 1;
            }

            m[v[i]] = i + 1;
        }

        return 0;
    }
};
