    bool comp(const pair<int, string> &x, const pair<int, string> &y){
        if (x.first == y.first){
            if (x.second > y.second){
                return 0;
            }else{
                return 1;
            }
        }else if (x.first < y.first){
            return 0;
        }else if (x.first > y.first){
            return 1;
        }
        return 0;
    }
    
class Solution {
public:
    set <string> st;
    unordered_map <string, int> m;



    vector<string> topKFrequent(vector<string>& words, int k) {
        vector <string> v;
        vector <pair<int, string>> z;
        for (string x : words){
            st.insert(x);
            ++m[x];
        }

        for (string x : st){
            z.push_back({m[x], x});
        }
        sort(z.begin(), z.end(), comp);
        for (int i = 0; i<k; ++i){
            v.push_back(z[i].second);
        }
        return v;
    }
};
