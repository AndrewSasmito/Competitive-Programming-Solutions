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

	freopen("holstein.in", "r", stdin);
	freopen("holstein.out", "w", stdout);

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

int n, x, m;
vector <int> vitamin;
vector <int> feed[16];
vector <pair<int, vector<int>>> ans;
bool vis[(1<<15)];
void calc(int mask, int i, vector <int>& v){
	if (i == m){
		bool f = 0;
		for (int j = 0; j<n; ++j){
			if (v[j] < vitamin[j]){
				f = 1;
				break;
			}
		}
		if (f == 0){
			//This is good
			vector <int> cur;
			for (int j = 0; j<m; ++j){
				if (!((mask&(1<<j)) == 0)){
					cur.push_back(j + 1);
				}
			}
			ans.push_back({i, cur});
		}
		return;
	}else if (vis[mask] == 1){
		return;
	}

	vis[mask] = 1;
	bool f = 0;
	for (int j = 0; j<n; ++j){
		if (v[j] < vitamin[j]){
			f = 1;
			break;
		}
	}
	if (f == 0){
		//This is good
		vector <int> cur;
		for (int j = 0; j<m; ++j){
			if (!((mask&(1<<j)) == 0)){
				cur.push_back(j + 1);
			}
		}
		ans.push_back({i, cur});
		return;
	}


	vector <int> now(n + 1);

	for (int j = 0; j<m; ++j){
		if ((mask&(1<<j)) == 0){
			for (int k = 0; k<n; ++k){
				now[k] = v[k] + feed[j][k];
			}
			calc(mask|(1<<j), i + 1, now);
		}
	}
}

void solve(){
	usaco();
	cin >> n;
	for (int i = 0; i<n; ++i){
		cin >> x;
		vitamin.push_back(x);
	}

	cin >> m;

	for (int i = 0; i<m; ++i){
		for(int j = 0; j<n; ++j){
			cin >> x;
			feed[i].push_back(x);
		}
	}
	vector <int> cur(n + 1);
	calc(0, 0, cur);
	sort(ans.begin(), ans.end());

	cout << ans[0].first;

	for (int x : ans[0].second){
		cout << ' ' << x;
	}
	cout << '\n';
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
	//ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


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

