#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, a, b, c, ans, m;
vector <int> adj[1001];
vector <int> cur(3);
void solve(){
	cin >> n;

	for (int i = 1; i<=n; ++i){
		cin >> a >> b >> c;

		adj[i].push_back(a);
		adj[i].push_back(b);
		adj[i].push_back(c);

		sort(adj[i].begin(), adj[i].end());
	}
	cin >> m;

	for (int i = 0; i<m; ++i){
		cin >> cur[0] >> cur[1] >> cur[2];
		sort(cur.begin(), cur.end());

		ans = 10000000000;

		for (int j = 1; j<=n; ++j){
			if (cur[0] <= adj[j][0] && cur[1] <= adj[j][1] && cur[2] <= adj[j][2]){
				ans = min(ans, adj[j][0] * adj[j][1] * adj[j][2]);
			}
		}

		if (ans == 10000000000)
			cout << "Item does not fit.\n";
		else
			cout << ans << '\n';
	}
}
signed main(){
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
