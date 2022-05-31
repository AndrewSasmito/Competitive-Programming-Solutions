#include <bits/stdc++.h>
using namespace std;

#define ll long long


pair<string, string> stay[100001], different[100001];
map <string, int> group;
void solve(){
    int n, ans = 0; cin>>n;

    for (int i = 1; i<=n; ++i){
        cin>>stay[i].first>>stay[i].second;

    }
    int diff;
    cin>>diff;

    for (int i = 1; i<=diff; ++i){
        cin>>different[i].first>>different[i].second;
    }

    int grouping; cin>>grouping;

    for (int i = 1; i<=grouping; ++i){
        string f, s, t;
        cin>>f>>s>>t;
        
        group[f] = i;
        group[s] = i;
        group[t] = i;
    }

    for (int i = 1; i<=n; ++i){
        if (group[stay[i].first] != group[stay[i].second]) ++ans;
    }
    for (int i = 1; i<=diff; ++i){
        if (group[different[i].first] == group[different[i].second]) ++ans;
    }

    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
