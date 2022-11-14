#include <bits/stdc++.h>
using namespace std;

int n, m, dp[1001][1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    vector <int> v1(n), v2(m);
    for (int i = 0 ; i<n; ++i){
        cin >> v1[i];
    }
    for (int i = 0; i<m; ++i){
        cin >> v2[i];
    }
    
    for (int i = 0; i<n; ++i){
        for (int j = 0; j<m; ++j){
            if (v1[i] == v2[j]){
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }else{
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    cout << dp[n][m] << '\n';
}
