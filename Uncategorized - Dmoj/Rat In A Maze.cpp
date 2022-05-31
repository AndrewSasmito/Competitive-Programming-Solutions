#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
int n;
bool vis[501][501];
void dfs(int x, int y){
	
	if (y < n)
		if (vis[x][y+1] == 0){
			vis[x][y+1] = 1;
			dfs(x, y + 1);
		}
	
	if (y > 1)
		if (vis[x][y-1] == 0){
			vis[x][y-1] = 1;
			dfs(x, y-1);
		}

	if (x < n)
		if (vis[x + 1][y] == 0){
			vis[x + 1][y] = 1;
			dfs(x + 1, y);
		}

	if (x > 1)
		if (vis[x - 1][y] == 0){
			vis[x - 1][y] = 1;
			dfs(x-1, y);
		}
}

void solve(){
	cin >> n;

	//rat starts at (1, 1), and check (n, n)
	for (int i = 1; i<=n; ++i){
		for (int j = 1; j<=n; ++j){
			cin >> vis[i][j];
		}
	}
	
	vis[1][1] = 1;
	dfs(1, 1);


	cout << (vis[n][n] == 1 ? "yes" : "no") << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	
    int testcases = 1;
   	//cin >> testcases;
    for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
    

    //Google
    //cout<<"Case #"<<number_of_total_test_cases<<": ";:
    // Normal
		solve();
    }

}
