#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
	ios::sync_with_stdio(NULL);
	cout.tie(NULL); cin.tie(NULL);
	
	while (true){
		cin >> n;

		if (n == 0)
			break;

		int a[n+1], dp[n+1][n+1];

		for (int i = 1; i <= n; ++i){
			cin>>a[i];	
		}

		for (int i = 1; i<=n; ++i){
			for (int j = 1; j<=n; ++j){
				dp[i][j] = 0;
			}
		}
		for (int len = 2; len < n; ++len){
			for (int i = 1; i + len <= n; ++i){
				int j = i + len;

				for (int m = i + 1; m < j; ++m){
					dp[i][j] = max(dp[i][j], dp[i][m] + dp[m][j] + a[i] + a[m] + a[j]);
				}
			}
		}
		cout << dp[1][n] << '\n';
	}
}
