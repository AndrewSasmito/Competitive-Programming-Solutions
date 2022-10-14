#include <bits/stdc++.h>
using namespace std;

int t, x, dp[11];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    while (t--){
        cin >> x;

        for (int i = 0; i<=x; ++i){
            dp[i] = 0;
        }
        dp[0] = 1;

        for (int i = 1; i<=x; ++i){
            for (int j = 1; j<=3; ++j){
                if (i < j)
                    break;

                dp[i] += dp[i - j];
            }
        }
        cout << dp[x] << '\n';
    }
}
