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

//Max and Min long long size
const ll mxll = 9223372036854775807, mnll = -9223372036854775807;
//Max and min int size
const int mxint = 2147483647, mnint = -2147483647;

void usaco(){

	freopen("2<.in", "r", stdin);
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

int n, m, f, s, nw, ls, pos;
void solve(){
	cin >> n >> m;
	vector <int> outcome(m), used(m), chck1(n), chck2(n);
	vector <string> hold(m);

	for (int i = 0; i<m; ++i){
		cin >> hold[i] >> outcome[i];
	}

	while (true){
		f = 0, s = 0;
		
		//part of a string is all one outcome

		for (int i = 0; i<n; ++i){
			bool fir = 0, sec = 0;
			nw = -1, ls = -1;
			for (int j = 0; j<m; ++j){
				if (used[j] == 1)
					continue;


				if (outcome[j] == 0 && (nw == hold[j][i] - '0' || nw == -1)){
					nw = hold[j][i] - '0';
				}else if (outcome[j] == 0){
					fir = 1;
				}


				if (outcome[j] == 1 && (ls == hold[j][i] - '0' || ls == -1)){
					ls = hold[j][i] - '0';
				}else if (outcome[j] == 1){
					sec = 1;
				}
			}
			if (fir == 0){
				/*if (ls == nw && sec == 0){
					continue;
				}
				*/
				if (chck1[i] == 1)
					continue;
				chck1[i] = 1;
				f = 1;
				pos = i;
				break;
			}
			
			if (sec == 0){
				/*if (ls == nw && fir == 0){
					continue;
				}
				*/
				if (chck2[i] == 1)
					continue;
				
				chck2[i] = 1;
				s = 1;
				pos = i;
				break;
			}
		}


		if (f == 1){
			for (int i = 0; i<m; ++i){
				if (outcome[i] == 1 && hold[i][pos] - '0' != nw){
					used[i] = 1;
				}
			}
		}
		if (s == 1){
			for (int i = 0; i<m; ++i){
				if (outcome[i] == 0 && hold[i][pos] - '0' != ls){
					used[i] = 1;
				}
			}
		}
		
		if (f == 0 && s == 0)
			break;

	}
	
	f = -1;



	for (int i = 0; i<m; ++i){
		if (used[i] == 0 && (outcome[i] == f || f == -1)){
			f = outcome[i];
		}else if (used[i] == 0){
			cout << "LIE\n";
			return;
		}
	}
	cout << "OK\n";
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

	cin >> testcases; 
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){

		//Google
		//cout<<"Case #"<<number_of_total_test_cases<<": ";

		// Normal
		solve();

    }

	//cout << elapsedTime << '\n';
}
