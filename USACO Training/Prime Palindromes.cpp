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

	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);

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

int x, y, cur;
set <int> s;

bool check(int x){
	for (int i = 3; i * i<=x; ++i){
		if (x % i == 0){
			return 0;
		}
	}
	return 1;
}



void solve(){
	usaco();
	cin >> x >> y;


	for (int i = 1; i<=9; ++i){
		if (x <= i && i <= y && i % 2 == 1 && check(i) == 1){
			s.insert(i);
		}
		cur = (i * 10) + i;

		if (x <= cur && cur <= y && i % 2 == 1 && check(cur) == 1){
			s.insert(cur);
		}
	}
	
	for (int a = 1; a<=9; a += 2){
		for (int b = 0; b<=9; ++b){
			cur = (a * 100) + (b * 10) + a;
			if (x <= cur && cur <= y && check(cur) == 1){
				s.insert(cur);
			}

			cur = (a * 1000) + (b * 100) + (b * 10) + a;
			if (x <= cur && cur <= y && check(cur) == 1){
				s.insert(cur);
			}
		}
	}
	for (int a = 1; a<=9; a += 2){
		for (int b = 0; b<=9; ++b){
			for (int c = 0; c<=9; ++c){

				cur = (a * 10000) + (b * 1000) + (c * 100) + (b * 10) + a;

				if (x <= cur && cur <= y && check(cur) == 1){
					s.insert(cur);
				}

				cur = (a * 100000) + (b * 10000) + (c * 1000) + (c * 100) + (b * 10) + a;
				if (x <= cur && cur <= y && check(cur) == 1){
					s.insert(cur);
				}
			}
		}
	}


	for (int a = 1; a<=9; a += 2){
		for (int b = 0; b<=9; ++b){
			for (int c = 0; c<=9; ++ c){
				for (int d = 0; d<=9; ++d){
					cur = (a * 1000000) + (b * 100000) + (c * 10000) + (d * 1000) + (c * 100) + (b * 10) + a;

					if (x <= cur && cur <= y && check(cur) == 1){
						s.insert(cur);
					}

					cur = (a * 10000000) + (b * 1000000) + (c * 100000) + (d * 10000) + (d * 1000) + (c * 100) + (b * 10) + a;

					if (x <= cur && cur <= y && check(cur) == 1){
						s.insert(cur);
					}
				}
			}
		}
	}

	for (int x : s){
		cout << x << '\n';
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

