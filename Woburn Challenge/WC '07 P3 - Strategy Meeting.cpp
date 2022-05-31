#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, x;
const int mod = 13371337;
ll dp[16][1 << 15];
vector <int> adj[15];

ll calc(int i, int num){
	if ((num >> (n-1) & 1) == 1)
			return 1;
	if (dp[i][num] != -1)
		return dp[i][num];

	int ret = 0;
	for (int x : adj[i]){
		if ((num >> x & 1) == 0){
			ret += calc(x, (num | (1 << x)));
			ret %= mod;
		}
	}
	return dp[i][num] = ret;
}
void solve(){
	cin >> n;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i<n; ++i){
		for (int j = 0; j<n; ++j){
			cin >> x;
			if (x == 1)
				adj[i].push_back(j);
		}
	}
	cout << calc(0, 1) << '\n';
	for (int i = 0; i<n; ++i){
		adj[i].clear();
	}
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int testcases = 1;
    cin >> testcases;
    for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
    

    //Google
    //cout<<"Case #"<<number_of_total_test_cases<<": ";
    // Normal
    solve();
    }

}
