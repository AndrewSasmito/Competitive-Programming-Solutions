#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dp[100001], n, x;
int main(){
    cin >> n >> x;
    vector <int> price(n), page(n);
    for (int i = 0; i<n; ++i){
        cin >> price[i];
    }
    for (int i = 0; i<n; ++i){
        cin >> page[i];
    }

    for (int i = 0; i<n; ++i){
        for (int j = x; j - price[i] >= 0; --j){
            dp[j] = max(dp[j], dp[j - price[i]] + page[i]);
        }
    }
    cout << dp[x] << '\n';
}
