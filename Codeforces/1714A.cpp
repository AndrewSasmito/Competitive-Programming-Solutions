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
};

//unordered_map<long long, int, custom_hash> safe_map;
//gp_hash_table<long long, int, custom_hash> safe_hash_table;

void usaco(){
	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);
}

int n, m, h, x, y, hcnt;
void solve(){
	vector <int> v[25];
	cin >> n >> h >> m;

	for (int i = 0; i<n; ++i){
		cin >> x >> y;
		v[x].push_back(y);
	}

	if (v[h].size() > 0){
		hcnt = 10000;
		for (int i = 0; i<v[h].size(); ++i){
			if (v[h][i] >= m){
				hcnt = min(hcnt, v[h][i] - m);
			}
		}

		if (hcnt != 10000){
			cout << 0 << ' ' << hcnt << '\n';
			return;
		}
	}
	int i;
	for (int z = 1; z<=25; ++z){
		i = (z + h) % 24;

		if (v[i].size() > 0){
			hcnt = 10000;

			for (int j = 0; j<v[i].size(); ++j){
				hcnt = min(hcnt, v[i][j]);
			}
			cout << --z + (((60 - m) + hcnt) > 59) << ' ' << ((60 - m) + hcnt)%60 << '\n';
			return;
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
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


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
