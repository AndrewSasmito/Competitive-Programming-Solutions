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
const int MX = 2e5 + 1;
int n, q, tree[2 * MX], x, a, b;

void build(){
	for (int i = n - 1; i>0; --i){
		tree[i] = min(tree[i<<1], tree[i<<1|1]);
	}
}

void modify(int i, int val){
	for (tree[i += n] = val; i>1; i >>= 1){
		tree[i>>1] = min(tree[i], tree[i^1]);
	}
}

int ret(int l, int r){
	int ans = mxint;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1){
		if (l&1) ans = min(ans, tree[l++]);
		if (r&1) ans = min(ans, tree[--r]);
	}
	return ans;
}

void solve(){
	cin >> n >> q;
	for (int i = 0; i<n; ++i){
		cin >> tree[i + n];
	}
	build();

	for (int i = 0; i<q; ++i){
		cin >> x >> a >> b;
		if (x == 1){
			modify(--a, b);
		}else{
			cout << ret(--a, b) << '\n';
		}
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
