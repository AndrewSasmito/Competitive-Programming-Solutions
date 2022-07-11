
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
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);
}
vector <int> xx;
vector <int> yy;
int pear[13];
int n, x, y, cnt = 0;

int rights(int i){
	int j = 0, js = 1000000000;

	int x = xx[i], y = yy[i];

	for (int a = 1; a<=n; ++a){
		if (a == i){
			continue;
		}
		if (y == yy[a] && js - x > xx[a] - x && xx[a] - x > 0){
			j = a;
			js = xx[a];
		}
	}
	return j;
}

bool fun(){
	int x;
	for (int i = 1; i<=n; ++i){
		x = i;
		for (int j = 1; j<=n; ++j){
			x = rights(pear[x]);

			if (x == 0){
				break;
			}
		}
		if (x != 0){
			return 1;
		}
	}	
	return 0;
}


void calc(){
	int i;
	for (i = 1; i<=n; ++i){
		if (pear[i] == 0){
			break;
		}
	}

	if (i == n + 1){
		cnt += fun();
		return;
	}

	for (int j = i + 1; j <= n; ++j){
		if (pear[j] == 0 && pear[i] == 0){
			pear[j] = i;
			pear[i] = j;

			calc();

			pear[i] = pear[j] = 0;
		}
	}
}

void solve(){
	usaco();
	cin >> n;

	xx.push_back(0);
	yy.push_back(0);
	for (int i = 0; i<n; ++i){
		cin >> x >> y;

		xx.push_back(x);
		yy.push_back(y);
	}

	calc();
	cout << cnt << '\n';
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
	//cin >> testcases; 
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
    


    //Google
    //cout<<"Case #"<<number_of_total_test_cases<<": ";
    // Normal
    solve();
    }

	//cout << elapsedTime << '\n';
}
