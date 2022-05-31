#include <bits/stdc++.h>
using namespace std;

#define int long long
vector <int> prim;
bool dp[1400002];
void precalc(){
    for (int i = 2; i<=1400002; ++i){
        if (dp[i] == 0){
            dp[i] = 1;
            prim.push_back(i);
            for (int j = i; j<=1400002; j += i)
                dp[j] = 1;
        }
    }
}
int a;
void solve(){
    cin >> a;
    
    
    for (int i = 0; i < prim.size(); ++i){
        auto it = lower_bound(prim.begin(), prim.end(), (2*a) - prim[i]);
        
        if (*it + prim[i] == 2*a){
            cout << *it << ' ' << prim[i] << '\n';
            return;
        }
    }
}
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    precalc();
    
    int t; cin >> t;
    
    for (int i = 0; i<t; ++i)
        solve();
}
