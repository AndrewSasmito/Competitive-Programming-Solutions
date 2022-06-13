#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int m, n, x, ans = 0;
vector <pair<int, int>> v1;
int a1[1001], a2[1001];
bool vis[1001];
void solve(){
	cin >> n >> m;

	for (int i = 1; i<=n; ++i){
		cin >> a1[i];
	}
	for (int i = 1; i<=n; ++i){
		cin >> a2[i];
	}

	for (int i = 1; i<=n; ++i){
		v1.push_back({a2[i] - a1[i], i});
	}
	sort(v1.begin(), v1.end(), greater<pair<int, int>>());


	for (int i = 0; i<m; ++i){
		ans += a2[v1[i].second];
		vis[v1[i].second] = 1;
	}

	for (int i = 1; i<=n; ++i){
		if (vis[i] == 0){
			ans += a1[i];
		}
	}

	cout << ans << '\n';
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
