#include <bits/stdc++.h>
using namespace std;

int dp[31], n, m, x;
unordered_set <int> s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for (int i = 0; i<n; ++i){
        x = 0;
        for (int j = 0, k; j<m; ++j){
            cin >> k;
            if (k == 1){
                x |= (1<<j);
            }
        }
        dp[i] = x;
    }
    x = dp[m - 1];
    s.insert(x);
    
    for (int i = n - 2; i>=0; --i){
        x ^= dp[i];
        s.insert(x);
    }
    cout << s.size() << '\n';
}
