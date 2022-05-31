#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


int dp[100001], x, y, z, n;
void solve(){
	cin>>n>>x>>y>>z;

	fill(dp, dp+100001, -1);
		dp[0] = 0;
	for (int i = 1; i<=n; ++i){
		if (i >= x && dp[i-x] != -1){
			dp[i] = max(dp[i], dp[i-x]+1);
		} if (i>=y && dp[i-y] != -1){
			dp[i] = max(dp[i], dp[i-y]+1);
		} if (i>=z && dp[i-z] != -1){
			dp[i] = max(dp[i], dp[i-z]+1);
		}
	}
	cout<<dp[n]<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int cases = 1; //cin>>cases;

	while (cases--) solve();
}
