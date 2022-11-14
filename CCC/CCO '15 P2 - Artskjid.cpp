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

	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);

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

int n, m, dp[(1<<19)][20], x, y, z;
vector <pair<int, int>> adj[19];

int dfs(int mask, int i, int ret, int cur){
    
    if (dp[mask][cur] == -1){
        return -1;
    }else if (dp[mask][cur] > 0){
        return dp[mask][cur] + ret;
    }else if ((mask&(1<<(n - 1)))){
		return ret;
	}else if (n - 1 == i){
		return -1;
	}

	int calc = -1;

	for (auto x : adj[cur]){
		if (x.first == 0){
			continue;
		}else if (!(mask&(1<<x.first))){
			calc = max(calc, dfs(mask|(1<<x.first), i + 1, x.second, x.first));
		}
	}
	//cout << mask << ' ' << cur << ' ' << calc << ' ' << ret << '\n';
    
    if (calc == -1){
        return dp[mask][cur] = -1;
    }else{
        dp[mask][cur] = calc;
        return calc + ret;
    }
}
void solve(){
	cin >> n >> m;

	for (int i = 0; i<m; ++i){
		cin >> x >> y >> z;
		adj[x].push_back({y, z});
	}

	x = dfs(0, 0, 0, 0);
	cout << x << '\n';
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
