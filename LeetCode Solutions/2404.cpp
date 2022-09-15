class Solution {
public:
    unordered_map <int, int> m;
    set <int> s;
    int mostFrequentEven(vector<int>& nums) {
        for (int x : nums){
            if (x % 2 == 0){
                s.insert(x);
                ++m[x];
            }
        }
        int num = -1, cnt = 0;
        for (int x : s){
            if (m[x] > cnt){
                cnt = m[x];
                num = x;
            }
        }
        return num;
    }
};
