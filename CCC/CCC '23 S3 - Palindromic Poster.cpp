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

int n, m, r, c;
char ans[2001][2001];
bool chck(){
	int rs = 0, cs = 0;
	for (int i = 0; i<n; ++i){
		bool f = 1;
		for (int j = 0; j<m/2; ++j){
			if (ans[i][j] != ans[i][m - j - 1]){
				f = 0;
				break;
			}
		}
		rs += f;
	}

	for (int i = 0; i<m; ++i){
		bool f = 1;
		for (int j = 0; j<n/2; ++j){
			if (ans[j][i] != ans[n - j - 1][i]){
				f = 0;
				break;
			}
		}
		cs += f;
	}

	//cout << cs << ' ' << rs << '\n';

	if (cs != c || rs != r){
		return 0;
	}
	return 1;
}
void debug(){
	for (int i = 0; i<n; ++i){
		for (int j = 0; j<m; ++j){
			cout << ans[i][j];
		}
		cout << '\n';
	}
}
char cd = 'a';
int nr, nc;
void solve(){
	cin >> n >> m >> r >> c;

	for (int i = 0; i<n; ++i){
		cd = (i % 24) + 'a';
		for (int j = 0; j<m; ++j){
			ans[i][j] = cd;
			++cd;
			if (cd > 'x')
				cd = 'a';
		}
	}
	nr = r;
	nc = c;

	if (n % 2 == 1 && r % 2 == 1){
		--nr;
		for (int i = 0; i<m; ++i){
			ans[n/2][i] = 'y';
		}
	}if (m % 2 == 1 && c % 2 == 1){
		--nc;
		for (int i = 0; i<n; ++i){
			ans[i][m/2] = 'y';
		}
	}

	for (int i = 0, cx = 0; cx<nr - 1; ++i, cx += 2){
		for (int j = 0; j<m/2; ++j){
			ans[i][j] = ans[i][m - j - 1];
			ans[n - i - 1][j] = ans[n - i - 1][m - j - 1];
		}
	}if (nr % 2 == 1){
		for (int i = 0; i<m; ++i){
			ans[n/2][i] = 'y';
		}
	}
	for (int i = 0, cx = 0; cx<nc - 1; cx += 2, ++i){
		for (int j = 0; j<n/2; ++j){
			ans[j][i] = ans[n - j - 1][i];
			ans[j][m - i - 1] = ans[n - j - 1][m - i - 1];
		}
	}if (nc % 2 == 1){
		for (int i = 0; i<n; ++i){
			ans[i][m/2] = 'y';
		}
	}

	for (int i = 0, cx = 0; cx<nr - 1; ++i, cx += 2){
		for (int j = 0; j<m/2; ++j){
			ans[i][j] = ans[i][m - j - 1];
			ans[n - i - 1][j] = ans[n - i - 1][m - j - 1];
		}
	}if (nr % 2 == 1){
		for (int i = 0; i<m; ++i){
			ans[n/2][i] = 'y';
		}
	}


	if (chck() == 0){
		cout << "IMPOSSIBLE\n";
		return;
	}
	
	for (int i = 0; i<n; ++i){
		for (int j = 0; j<m; ++j){
			cout << ans[i][j];
		}
		cout << '\n';
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
