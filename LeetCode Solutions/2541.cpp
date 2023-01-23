class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0, cnt = 0;
        for (int i = 0; i < nums1.size(); ++i){
            if (nums1[i] != nums2[i] && k == 0){
                return -1;
            }else if (k != 0 && nums1[i] % k != nums2[i] % k){
                return -1;
            }
            
            cnt += nums1[i] - nums2[i];
            ans += abs(nums1[i] - nums2[i]);
        }
        if (cnt != 0){
            return -1;
        }else if (k == 0){
            return 0;
        }
        return ans / k / 2;
    }
};
