#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

vector <pair<int, int>> adj[100001];
int n, x, y, z;
bool vis[100001];
bool ans[100001];
void dfs(int x, int dis){
	vis[x] = 1;

	for (int s = 0; s < adj[x].size(); ++s){
		if (vis[adj[x][s].first] == 1)
			continue;

		int cur = dis + adj[x][s].second;

		if (cur % 2 == 0){
			ans[adj[x][s].first] = 0;
		}else{
			ans[adj[x][s].first] = 1;
		}

		dfs(adj[x][s].first, cur);
	}
}

void solve(){
	cin >> n;

	for (int i = 0; i<n - 1; ++i){
		cin >> x >> y >> z;

		adj[x].push_back({y, z});
		adj[y].push_back({x, z});
	}
	
	dfs(1, 0);

	for (int i = 1; i<=n; ++i){
		cout << ans[i] << ' ' ;
	}
	cout << '\n';
}


/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

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

	//cout << elapsedTime << '\n';
}
