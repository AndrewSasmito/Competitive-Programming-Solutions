class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        vector <int> ret(v.size());
        stack <int> s;

        for (int i = 0; i<v.size(); ++i){
            while (s.size() && v[s.top()] < v[i]){
                ret[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }

        while (s.size()){
            ret[s.top()] = 0;
            s.pop();
        }

        return ret;
    }
};
