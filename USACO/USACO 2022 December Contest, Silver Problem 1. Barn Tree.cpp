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
struct cs{
	ll from, tos, num;
};
const int MX = 2e5 + 1;
int n;
vector <int> adj[MX];
vector <cs> f, s;
int deg[MX];
bool vis[MX];
ll barn[MX], tot = 0;
queue <int> q;
void solve(){
	cin >> n;

	for (int i = 1; i<=n ;++i){
		cin >> barn[i];
		tot += barn[i];
	}

	tot /= n;

	for (int i = 0, x, y; i<n - 1; ++i){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		++deg[x], ++deg[y];
	}

	for (int i = 1; i<=n; ++i){
		if (deg[i] == 1){
			q.push(i);
		}
	}

	while (q.size()){
		int cur = q.front();
		q.pop();
		
		if (vis[cur] == 1){
			continue;
		}
		vis[cur] = 1;

		for (int x : adj[cur]){
			if (vis[x] == 0){
				if (barn[cur] > tot){
					cs h;
					h.from = cur, h.tos = x, h.num = barn[cur] - tot;
					barn[x] += h.num;
					f.push_back(h);
				}else if (barn[cur] < tot){
					cs h;
					h.from = x, h.tos = cur, h.num = tot - barn[cur];
					barn[x] -= h.num;
					s.push_back(h);
				}
			}
			--deg[x];
			if (deg[x] == 1 && vis[x] == 0){
				q.push(x);
			}
		}
	}
	
	cout << s.size() + f.size() << '\n';

	for (int i = 0; i<f.size(); ++i){
		cout << f[i].from << ' ' << f[i].tos << ' ' << f[i].num << '\n';
	}
	for (int i = s.size() - 1; i>=0; --i){
		cout << s[i].from << ' ' << s[i].tos << ' ' << s[i].num << '\n';
	}
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
