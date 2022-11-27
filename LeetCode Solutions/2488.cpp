class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map <int, int> m;
        int pos = -1, cnt1 = 0, cnt2 = 0, ret = 1;
        for (int i = 0; i<nums.size(); ++i){
            if (nums[i] == k){
                pos = i;
                break;
            }
        }
        
        if (pos == -1){
            return 0;
        }
        
        for (int i = pos - 1; i>=0; --i){
            if (nums[i] < k){
                ++cnt1;
            }else{
                ++cnt2;
            }
            
            if (cnt1 == cnt2 || cnt1 + 1 == cnt2){
                ++ret;
            }
            ++m[cnt2 - cnt1];
            ++m[cnt2 - cnt1 - 1];
        }
        cnt1 = 0, cnt2 = 0;
        for (int i = pos + 1; i<nums.size(); ++i){
            if (nums[i] < k){
                ++cnt1;
            }else{
                ++cnt2;
            }
            if (cnt1 == cnt2 || cnt1 + 1 == cnt2){
                ++ret;
            }

            ret += m[cnt1 - cnt2];
        }
        return ret;
    }
};
