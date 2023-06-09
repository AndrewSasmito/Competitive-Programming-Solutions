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
 
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
 
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

int n, g, l, r, cnt, tot;
string s;
set <int> ans;
char st;
void solve(){
	cin >> n >> s;
	g = 1, l = 0, r = n - 1;
	for (int i = 0; i<n; ++i){
		if (s[i] != 'F'){
			g = 0;
		}
	}
	if (g == 1){
		cout << n << '\n';
		for (int i = 0; i<n; ++i)
			cout << i << '\n';
		return;
	}
	while (s[l] == 'F')
		++l;
	while (s[r] == 'F')
		--r;

	st = s[l], cnt = 0;
	for (int i = l + 1; i<=r; ++i){
		if (s[i] != 'F'){
			if (st == s[i]){
				//Same
				if (cnt % 2 == 0){
					++g;
				}else{
					++cnt;
				}
				tot += max(cnt/2, 0);
			}else{
				//Diff
				if (cnt % 2 == 1){
					++g;
					--cnt;
				}
				tot += max(0, cnt/2);
			}

			cnt = 0;
			st = s[i];
		}else{
			++cnt;
		}
	}

	//cout << l << ' ' << r << ' ' << g << ' ' << tot << '\n';
	for (int i = 0; i<=tot; ++i){
		for (int j = 0; j<= l + (n - r - 1); ++j){
			ans.insert((2 * i) + j + g);
		}
	}

	cout << ans.size() << '\n';
	for (int x : ans)
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
