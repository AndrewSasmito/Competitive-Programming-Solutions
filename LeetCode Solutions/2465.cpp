class Solution {
public:
    multiset <int> cur;
    unordered_set <int> even, odd;
    int distinctAverages(vector<int>& nums) {
        for (int x : nums){
            cur.insert(x);
        }
        
        while (cur.size()){
            int mn = *(cur.begin()), mx = *(cur.rbegin());
            
            if ((mn + mx) % 2 == 0){
                even.insert((mn + mx) / 2);
            }else{
                odd.insert((mn + mx) / 2);
            }
            
            cur.erase(cur.begin());
            cur.erase(--cur.end());
        }
        
        return even.size() + odd.size();
    }
};
