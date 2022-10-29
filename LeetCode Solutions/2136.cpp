#define ll long long
bool cmp(const pair<ll, ll> &x, const pair<ll, ll> &y){
    if (x.first == y.first){
        if (x.second < y.second){
            return 1;
        }else{
            return 0;
        }
    }else if (x.first < y.first){
        return 0;
    }else{
        return 1;
    }
}

class Solution {
public:
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        ll ans = -1, day = 0;
        vector <pair<ll, ll>> v;

        for (int i = 0; i<plantTime.size(); ++i){
            v.push_back({growTime[i], plantTime[i]});
        }
        sort(v.begin(), v.end(), cmp);

        for (int i = 0; i<v.size(); ++i){
            day += v[i].second;

            ans = max(ans, day + v[i].first);
        }
        return ans;
    } 
};
