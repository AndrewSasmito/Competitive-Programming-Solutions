#include <bits/stdc++.h>
using namespace std;


bool primes[7001];
int dp[7001];
void prime(int n, int tot){
	for (int p = 2; p<=n; ++p){
		if (primes[p] == 0){
			for (int i = p; i<=n; ++i){
				dp[i] = min(dp[i], dp[i-p] + 1);
			}

			for (int i=p*2; i<=n; i+= p){
				primes[i] = 1;
			}
		}
	}
}

void solve(){
	memset(dp, 7002, sizeof(dp));
	
	dp[0] = 0;
	int n, k, ans = 0;
	cin>>n>>k;
	
	prime(n, k);

	for(int i = 0; i<=n; ++i){
		if (dp[i] == k) ++ans;
	}
	cout<<ans<<'\n';
}







int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int cases = 1; //cin>>cases;

	while (cases--) solve();
}
