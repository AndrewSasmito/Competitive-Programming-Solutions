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

	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);

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

int n, cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0, cur;
int v[4][3];
void solve(){
	usaco();
	cin >> n;
	vector <int> x(n);
	for (int i = 0; i<n; ++i){
		cin >> x[i];

		if (x[i] == 1){
			++cnt1;
		}else if (x[i] == 2){
			++cnt2;
		}else{
			++cnt3;
		}
	}

	for (int i = 0; i<cnt1; ++i){
		if (x[i] == 2){
			++v[1][2];
		}else if (x[i] == 3){
			++v[1][3];
		}
	}

	for (int i = cnt1; i<cnt2 + cnt1; ++i){
		if (x[i] == 1){
			++v[2][1];
		}else if (x[i] == 3){
			++v[2][3];
		}
	}

	for (int i = cnt1 + cnt2; i < n; ++i){
		if (x[i] == 1){
			++v[3][1];
		}else if (x[i] == 2){
			++v[3][2];
		}
	}

	cur = min(v[1][2], v[2][1]);
	ans += cur;
	v[1][2] -= cur, v[2][1] -= cur;

	cur = min(v[1][3], v[3][1]);
	ans += cur;
	v[1][3] -= cur, v[3][1] -= cur;

	cur = min(v[2][3], v[3][2]);
	ans += cur;
	v[2][3] -= cur, v[3][2] -= cur;
	cur = v[1][2] + v[1][3] + v[2][1] + v[2][3] + v[3][1] + v[3][2];
	ans += (cur / 3) * 2;
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

