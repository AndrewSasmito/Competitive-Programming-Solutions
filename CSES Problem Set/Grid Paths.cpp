#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e9 + 7;
ll dp[1001][1001];
char grid[1001][1001];
string s;
int n;
int main(){
    cin >> n;
    for (int i = 1; i<=n; ++i){
        cin >> s;
        for (int j = 1; j<=n; ++j){
            grid[i][j] = s[j - 1];
        }
    }
    if (grid[1][1] == '*'){
        cout << 0 << '\n';
        return 0;
    }
    dp[1][1] = 1;
    for (int i = 1; i<=n; ++i){
        for (int j = 1; j<=n; ++j){
            if (grid[i][j] == '*')
                continue;

            dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }

    cout << dp[n][n] << '\n';
}
