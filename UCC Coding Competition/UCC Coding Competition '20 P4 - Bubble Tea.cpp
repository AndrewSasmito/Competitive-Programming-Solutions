#include <bits/stdc++.h>
using namespace std;

#define ll long long


int dp[1000001];
int nums[1000001];
void solve(){
	int n;
	cin>>n;
	
	memset(dp, 1002, sizeof(dp));
	for (int i = 1; i<=n; ++i){
		cin>>nums[i];

	}

	dp[0] = 0;

	for (int i = 1; i<=n; ++i){
		dp[i] = dp[i-1] + nums[i];
		if (i>1){
			//code

			dp[i] = min(dp[i], dp[i-2] + nums[i-1] + nums[i] - (min(nums[i-1], nums[i])/4));
		}

		if (i>2){
			//code
			dp[i] = min(dp[i], dp[i-3] + nums[i-2] + nums[i-1] + nums[i] - (min(nums[i], min(nums[i-1], nums[i-2]))/2));
		}


	}

	cout<<dp[n]<<'\n';
}





 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
