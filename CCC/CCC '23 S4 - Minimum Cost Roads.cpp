#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedtime ((double)(clock()-__init_time__)/clocks_per_sec)<<" seconds"
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
//custom hash for hash map
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t fixed_random = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + fixed_random);
    }
 
	/*
	 	* How To Use:
	 	*
	 	* unordered_map<long long, int, custom_hash> safe_map;
	 	* gp_hash_table<long long, int, custom_hash> safe_hash_table;
	 	*
	 */
};
 
//Max and Min long long size
const ll mxll = 9223372036854775807, mnll = -9223372036854775807;
//Max and min int size
const int mxint = 2147483647, mnint = -2147483647;
 
void usaco(){
 
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
 
	/*
		 * How To Use:
		 *
		 * Call usaco() to take input and output
		 * to & from a textfile
		 *
		 * freopen("File Name", "r" or "w", stdin or stdout);
		 *
		 * r && stdin == read
		 *
		 * w && stdout == print
		 *
	 */
}
const int MX = 2001;
bool vis[MX];
int n, m, cx = 0;
ll ans[MX][MX], a, b, c, d, ret = 0;
vector <pair<ll, ll>> adj[MX];
priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;

void dij(int x){
	q.push({0, x});
	for (int i = 1; i<=n; ++i){
		vis[i] = 0;
	}
		while(q.size()){
			ll lens = q.top().first, nd = q.top().second;
			q.pop();
			if (vis[nd] == 1){
				continue;
			}
			vis[nd] = 1;

			if (ans[x][nd] > lens){
				ans[x][nd] = lens;
				ans[nd][x] = lens;
			}

			for (auto x : adj[nd]){
				if (vis[x.second] == 0){
					q.push({x.first + lens, x.second});
				}
			}
		}

}

void solve(){
	cin >> n >> m;
	vector <pair<ll, pair<ll, pair<ll, ll>>>> v(m);
	for (int i = 0; i<m; ++i){
		cin >> a >> b >> c >> d;
		v[i].first = c, v[i].second.first = d, v[i].second.second.first = a, v[i].second.second.second = b;
	}
	sort(v.begin(), v.end());

	for (int i = 1; i<=n; ++i){
		for (int j = 1; j<=n; ++j){
			ans[i][j] = mxll;
		}
	}
	for (int i = 0; i<m; ++i){
		dij(v[i].second.second.first);
		for (int i = 1; i<=n; ++i)
			vis[i] = 0;

		bool f = 0;
		q.push({v[i].first, v[i].second.second.second});
		q.push({0, v[i].second.second.first});

		while (q.size()){
			ll lens = q.top().first, nd = q.top().second;
			q.pop();
			if (vis[nd] == 1){
				continue;
			}
			vis[nd] = 1;

			if (ans[v[i].second.second.first][nd] > lens){
				ans[v[i].second.second.first][nd] = lens;
				ans[nd][v[i].second.second.first] = lens;
				if (nd != v[i].second.second.first){
					//cout << "HERE: " << i << ' ' << v[i].second.second.first << ' ' << nd << ' ' << lens << '\n';
					f = 1;
				}
			}

			for (auto x : adj[nd]){
				if (vis[x.second] == 0){
					q.push({x.first + lens, x.second});
				}
			}
		}
		if (f == 1){
			adj[v[i].second.second.second].push_back({v[i].first, v[i].second.second.first});
			adj[v[i].second.second.first].push_back({v[i].first, v[i].second.second.second});
			ret += v[i].second.first;
		}
	}


	cout << ret << '\n';
}
//do not submit if usaco(); is open
 
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
 
int main(){
	//Speed up
	ios::sync_with_stdio(0); cin.tie(0);
	
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
