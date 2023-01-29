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

int n, q, x, y, tot = 0, tmp;
int pos[300001], nxt[300001];
void solve(){
	cin >> n >> q;
	//mod N

	for (int i = 0; i<n; ++i){
		cin >> x;

		pos[x] = i;
	}

	for (int i = 1; i<=n; ++i){
		if ((pos[i] + 1) % n == pos[max(1, (i + 1) % (n + 1))]){
			nxt[i] = 1;
			++tot;
		}
	}

	for (int i = 0; i<q; ++i){
		cin >> x >> y;
		
		tmp = x - 1;
		if (x - 1 == 0)
			tmp = n;
		
		cout << "FIRST: " << tot << '\n';

		if ((pos[x] + 1) % n == pos[max(1, (x + 1) % (n + 1))]){
			tot -= nxt[x];
			nxt[x] = 0;
		}if ((pos[tmp] + 1) % n == pos[max(1, x % (n + 1))]){
			tot -= nxt[tmp];
			nxt[tmp] = 0;
		}

		tmp = y - 1;
		if (y - 1 == 0)
			tmp = n;

		if ((pos[y] + 1) % n == pos[max(1, (y + 1) % (n + 1))]){
			tot -= nxt[y];
			nxt[y] = 0;
		}if ((pos[tmp] + 1) % n == pos[max(1, y % (n + 1))]){
			tot -= nxt[tmp];
			nxt[tmp] = 0;
		}

		tmp = pos[y];

		pos[y] = pos[x];
		pos[x] = tmp;

		tmp = x - 1;
		if (x - 1 == 0)
			tmp = n;

		if ((pos[x] + 1) % n == pos[max(1, (x + 1) % (n + 1))]){
			tot += 1 - nxt[x];
			nxt[x] = 1;
		}if ((pos[tmp] + 1) % n == pos[max(1, x % (n + 1))]){
			tot += 1 - nxt[tmp];
			nxt[tmp] = 1;
		}

		tmp = y - 1;
		if (y - 1 == 0)
			tmp = n;

		if ((pos[y] + 1) % n == pos[max(1, (y + 1) % (n + 1))]){
			tot += 1 - nxt[y];
			nxt[y] = 1;
		}if ((pos[tmp] + 1) % n == pos[max(1, y % (n + 1))]){
			tot += 1 - nxt[tmp];
			nxt[tmp] = 1;
		}


		cout << "FIRST: " << tot << '\n';
		if (tot == n){
			cout << "DA\n";
		}else{
			cout << "NE\n";
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
