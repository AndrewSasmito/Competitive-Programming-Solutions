#include <bits/stdc++.h>
using namespace std;

unordered_map <int, int> m;
unordered_set <int> st;
int n, x, cnt1, cnt2, mn = 1001, mx = -1;
vector <pair<int, int>> v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i<n; ++i){
        cin >> x;
        ++m[x];
        st.insert(x);
    }

    for (int x : st){
        v.push_back({m[x], x});
    }

    sort(v.begin(), v.end(), greater<pair<int, int>>());

    cnt1 = v[0].first;
    cnt2 = v[1].first;
    if (cnt1 == cnt2){
        for (auto x : v){
            if (x.first == cnt1){
                mn = min(x.second, mn);
                mx = max(x.second, mx);
            }
        }
        cout << mx - mn << '\n';
    }else{
        for (auto x : v){
            if (x.first == cnt2){
                mn = min(x.second, mn);
                mx = max(x.second, mx);
            }
        }
        cout << max(abs(v[0].second - mx), abs(v[0].second - mn)) << '\n';
    }
}
