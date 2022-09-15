class Solution {
public:
    unordered_set <int> s;
    int minimumOperations(vector<int>& nums) {
        for (int x : nums){
            if (x > 0){
                s.insert(x);
            }
        }
        return s.size();
    }
};
