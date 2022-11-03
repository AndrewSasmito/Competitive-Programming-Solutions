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

	freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);

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

int n, m, ans = 0;
bool grid[101][101];
string s;

void bfs(int i, int j){
	queue <pair<int, int>> q;

	q.push({i, j});
	grid[i][j] = 1;

	while (q.size()){
		int curx = q.front().first, cury = q.front().second;
		q.pop();

		if (curx != n && grid[curx + 1][cury] != 1){
			q.push({curx + 1, cury});
			grid[curx + 1][cury] = 1;
		}

		if (cury != m && grid[curx][cury + 1] != 1){
			q.push({curx, cury + 1});
			grid[curx][cury + 1] = 1;
		}

		if (curx != 1 && grid[curx - 1][cury] != 1){
			q.push({curx - 1, cury});
			grid[curx - 1][cury] = 1;
		}

		if (cury != 1 && grid[curx][cury - 1] != 1){
			q.push({curx, cury - 1});
			grid[curx][cury - 1] = 1;
		}
	}
}

void solve(){
	cin >> n >> m;
	for (int i = 1; i<=n; ++i){
		cin >> s;

		for (int j = 1; j<=m; ++j){
			if (s[j - 1] == 'X'){
				grid[i][j] = 1;
			}
		}
	}

	for (int i = 1; i<=n; ++i){
		for (int j = 1; j<=m; ++j){
			if (grid[i][j] == 0){
				++ans;
				bfs(i, j);
			}
		}
	}
	cout << ans << '\n';
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

