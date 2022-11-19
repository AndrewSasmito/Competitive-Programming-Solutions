/*
ID: asasmit1
TASK: numtri
LANG: C++
*/
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

ll n, sc1[1001], sc2[1001], dp[1001][1001];
string s, t;
void solve(){
	cin >> n >> s;
	for (int i = 0; i<n; ++i){
		cin >> sc1[i];
	}
	cin >> t;
	for (int i = 0; i<n; ++i){
		cin >> sc2[i];
	}

	for (int i = 0; i<n; ++i){
		for (int j = 0; j<n; ++j){
			bool f = 0;
			if (s[i] == 'W' && t[j] == 'L'){
				//Water won and Laurier lost
				if (sc1[i] > sc2[j]){
					dp[i][j] = sc1[i] + sc2[j];
					f = 1;
				}
			}else if (s[i] == 'L' && t[j] == 'W'){
				//Laurier won and water lost
				if (sc1[i] < sc2[j]){
					dp[i][j] = sc1[i] + sc2[j];
					f = 1;
				}
			}

			//Dp
			if (i == 0 && j == 0){
				continue;
			}else if (i == 0){
				dp[i][j] = max(dp[i][j], dp[i][j - 1]);
				continue;
			}else if (j == 0){
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				continue;
			}else if (f == 1){
				dp[i][j] += dp[i - 1][j - 1];
			}

			dp[i][j] = max(dp[i][j], max(dp[i][j - 1], dp[i - 1][j]));
		}
	}
	cout << dp[n - 1][n - 1] << '\n';
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
