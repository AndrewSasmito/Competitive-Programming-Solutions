class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ret = 0, x;
        priority_queue <long long> q;
        for (int x : nums)
            q.push(x);
        
        for (int i = 0; i<k; ++i){
            ret += q.top();
            x = (q.top() + 2) / 3;
            q.pop();
            q.push(x);
        }
        
        return ret;
    }
};
