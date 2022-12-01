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

int psa[1501][1501], n, m;
queue <pair<int, int>> q;
bool vis[1501][1501];
vector <string> v;
string s;

bool check(int x){

	for (int i = 0; i<n; ++i){
		for (int j = 0; j<m; ++j){
			vis[i][j] = 0;
		}
	}
	
	if (psa[x - 1][x - 1] < x){
		return 0;
	}

	vis[x - 1][x - 1] = 1;
	q.push({x - 1, x - 1});

	while (q.size()){
		int cury = q.front().first, curx = q.front().second;
		q.pop();

		if (cury != 0 && vis[cury - 1][curx] == 0 && psa[cury - 1][curx] >= x){
			q.push({cury - 1, curx});
			vis[cury - 1][curx] = 1;
		}
		if (cury != n - 1 && vis[cury + 1][curx] == 0 && psa[cury + 1][curx] >= x){
			q.push({cury + 1, curx});
			vis[cury + 1][curx] = 1;
		}
		if (curx != 0 && vis[cury][curx - 1] == 0 && psa[cury][curx - 1] >= x){
			q.push({cury, curx - 1});
			vis[cury][curx - 1] = 1;
		}
		if (curx != m - 1 && vis[cury][curx + 1] == 0 && psa[cury][curx + 1] >= x){
			q.push({cury, curx + 1});
			vis[cury][curx + 1] = 1;
		}
	}

	return vis[n - 1][m - 1];
}

void solve(){
	cin >> n >> m;

	for (int i = 0; i<n; ++i){
		cin >> s;
		v.push_back(s);
	}

	for (int i = 0; i<m; ++i){
		if (v[0][i] == 'O')
			psa[0][i] = 1;
	}

	for (int i = 1; i<n; ++i){
		if (v[i][0] == 'O')
			psa[i][0] = 1;
	}

	for (int i = 1; i<n; ++i){
		for (int j = 1; j<m; ++j){
			if (v[i][j] == 'O'){
				psa[i][j] = min(psa[i - 1][j], min(psa[i - 1][j - 1], psa[i][j - 1])) + 1;
			}

		}
	}

	int lo = 1, hi = 1500, ans = 1;
	
	while (lo < hi){
		int mid = (lo + hi) / 2;

		if (check(mid)){
			ans = mid;
			lo = mid + 1;
		}else{
			hi = mid - 1;
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
