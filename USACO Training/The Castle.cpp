#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedtime ((double)(clock()-__init_time__)/clocks_per_sec)<<" seconds"
#define ll long long
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



void usaco(){

	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);

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

int n, m, x, rmcnt = 0, mx = 0, curx, cury, cur, cnt;
char ans;
vector <pair<int, int>> adj[51][51];
bool vis[51][51];

int bfs(int x, int y){
	int ret = 1;
	vis[x][y] = 1;
	queue <pair<int, int>> q;
	q.push({x, y});
	while (q.size()){
		int curx = q.front().first, cury = q.front().second;
		q.pop();

		for (auto z : adj[curx][cury]){
			if (vis[z.first][z.second] == 1){
				continue;
			}

			vis[z.first][z.second] = 1;
			++ret;

			q.push({z.first, z.second});
		}
	}
	return ret;
}

void clean(){
	for (int i = 0; i<51; ++i)
		for (int j = 0; j<51; ++j)
			vis[i][j] = 0;
}

void solve(){
	usaco();
	cin >> n >> m;

	for (int i = 0; i<m; ++i){
		for (int j = 0; j<n; ++j){
			cin >> x;
			for (int k = 0; k<4; ++k){
				if ((x&(1<<k)) == 0){
					if (k == 0)
						adj[i][j].push_back({i, j - 1});
					else if (k == 1)
						adj[i][j].push_back({i - 1, j});
					else if (k == 2)
						adj[i][j].push_back({i, j + 1});
					else
						adj[i][j].push_back({i + 1, j});
				}
			}
		}
	}

	for (int i = 0; i<m; ++i){
		for (int j = 0; j<n; ++j){
			if (vis[i][j] == 0){
				++rmcnt;
				mx = max(mx, bfs(i, j));
			}
		}
	}

	cout << rmcnt << '\n' << mx << '\n';

	mx = 0;
	for (int j = 0; j<n; ++j){
		for (int i = m - 1; i>=0; --i){
			bool north = 0, south = 0, east = 0, west = 0;

			for (auto x : adj[i][j]){
				if (x.first == i + 1){
					south = 1;
				}else if (x.first == i - 1){
					north = 1;
				}else if (x.second == j + 1){
					east = 1;
				}else if (x.second == j - 1){
					west = 1;
				}
			}
			if (i != 0 && north == 0){
				clean();
				cur = bfs(i - 1, j);
				if (vis[i][j] == 0){
					cur += bfs(i, j);
				}

				if (cur > mx){
					mx = cur, curx = i, cury = j, ans = 'N';
				}
			}
			if (i != m - 1 && south == 0){
				clean();
				cur = bfs(i + 1, j);
				if (vis[i][j] == 0){
					cur += bfs(i, j);
				}
				if (cur > mx){
					mx = cur, curx = i, cury = j, ans = 'S';
				}
			}
			if (j != 0 && west == 0){
				clean();
				cur = bfs(i, j - 1);
				if (vis[i][j] == 0){
					cur += bfs(i, j);
				}
				if (cur > mx){
					mx = cur, curx = i, cury = j, ans = 'W';
				}

			}
			if (j != n - 1 && east == 0){
				clean();
				cur = bfs(i, j + 1);
				if (vis[i][j] == 0){
					cur += bfs(i, j);
				}
				if (cur > mx){
					mx = cur, curx = i, cury = j, ans = 'E';
				}
			}

		}
	}

	cout << mx << '\n' << curx + 1 << ' ' << cury + 1 << ' ' << ans << '\n';
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

