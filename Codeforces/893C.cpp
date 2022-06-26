#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, m, x, y;
ll score[100001], ans = 0;
vector <int> adj[100001];
bool vis[100001];
queue <int> q;

ll calc(int h){
	ll cur = score[h];
	vis[h] = 1;
	q.push(h);

	while (q.size()){
		int curs = q.front();
		q.pop();

		for (int x : adj[curs]){
			if (vis[x])
				continue;

			vis[x] = 1;

			cur = min(score[x], cur);

			q.push(x);
		}
	}

	return cur;
}


void solve(){
	cin >> n >> m;

	for (int i = 1; i<=n; ++i){
		cin >> score[i];
	}


	for (int i = 0; i<m; ++i){
		cin >> x >> y;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}


	for (int i = 1; i<=n; ++i){
		if (vis[i])
			continue;

		ans += calc(i);
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
