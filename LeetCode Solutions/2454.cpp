class Solution {
public:    
    vector<int> secondGreaterElement(vector<int>& nums) {
        vector <int> ans;
        for (int i = 0; i<nums.size(); ++i){
            ans.push_back(-1);
        }
        stack <int> f, s, temp;
        
        for (int i = 0; i<nums.size(); ++i){
            while (!(s.empty()) && nums[s.top()] < nums[i]){
                ans[s.top()] = nums[i];
                s.pop();
            }while (!(f.empty()) && nums[f.top()] < nums[i]){
                temp.push(f.top());
                f.pop();
            }while (!(temp.empty())){
                s.push(temp.top());
                temp.pop();
            }
            f.push(i);
        }
        
        
        return ans;
    }
};
