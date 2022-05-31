#include <bits/stdc++.h>
using namespace std;
int t, n, k, w, dp[501][30001], pin[30001];
int main(){
    cin>>t;
    for (int z = 1; z<=t; ++z){
        cin>>n>>k>>w;
        for(int i=1; i<=n; ++i){
            cin>>pin[i];
			pin[i] += pin[i-1];
        }

        for(int i=1; i<=k; ++i){
            for(int j=1; j<=n; ++j){
                if(j <= w) dp[i][j] = pin[j];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j-w]+pin[j]-pin[j-w]);
            }
        }
        cout<<dp[k][n]<<'\n';
    }
}
