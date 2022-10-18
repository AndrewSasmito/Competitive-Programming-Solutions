#include <bits/stdc++.h>
using namespace std;

string s, t;
int dp[1001][1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;

    for (int i = 0; i<s.size(); ++i){
        for (int j = 0; j<t.size(); ++j){
            if (s[i] == t[j]){
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }else{
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    cout << dp[s.size()][t.size()] << '\n';
}
