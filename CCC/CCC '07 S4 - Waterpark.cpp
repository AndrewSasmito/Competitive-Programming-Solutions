#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, x, y;
vector <int> adj[10000];
int dp[10000];
int dfs(int x){
	
	if (dp[x] > 0)
	    return dp[x];
	else if (x == n)
		return 1;
	else if (adj[x].size() == 0)
	    return 0;

	int ans = 0;

	for (int d : adj[x]){
		ans += dfs(d);
	}

	return dp[x] = ans;
}

void solve(){
	cin >> n;

	while (true){
		cin >> x >> y;
		if (x == 0 && y == 0)
			break;

		adj[x].push_back(y);
	}
    dp[n] = 1;
	cout << dfs(1) << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int testcases = 1;
    //cin >> testcases;
    for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
    

    //Google
    //cout<<"Case #"<<number_of_total_test_cases<<": ";
    // Normal
    solve();
    }

}
