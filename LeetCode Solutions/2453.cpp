class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        sort(nums.begin(), nums.end());
        unordered_map <int, int> m;
        for (int i = 0; i < nums.size(); ++i){
            ++m[nums[i] % space];                
        }
        
        int mx = -1, cnt = -1;
        for (int x : nums){
            if (m[x % space] > cnt){
                cnt = m[x % space];
                mx = x;
            }
        }
        
        return mx;
    }
};
