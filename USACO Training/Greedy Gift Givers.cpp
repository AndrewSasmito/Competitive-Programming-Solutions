#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


//Custom hash for hash map
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//unordered_map<long long, int, custom_hash> safe_map;
//gp_hash_table<long long, int, custom_hash> safe_hash_table;

void usaco(){
	freopen("gift1.in", "r", stdin);
	freopen("gift1.out", "w", stdout);
}

//do not submit if usaco(); is open

unordered_map <string, int> m;
vector <string> v;
int n, z, x, dp[11];
string s;
void solve(){
	usaco();
	cin >> n;

	for (int i = 1; i<=n; ++i){
		cin >> s;
		m[s] = i;
		v.push_back(s);
	}

	for (int i = 0; i<n; ++i){
		cin >> s >> x >> z;

		if (x > 0 && z > 0){
			dp[m[s]] -= (x / z) * z;
		}


		for (int i = 0; i<z; ++i){
			cin >> s;
			if (x > 0 && z > 0){

				dp[m[s]] += (x/z);
			}
		}
	}

	for (int i = 0; i<n; ++i){
		cout << v[i] << ' ' << dp[m[v[i]]] << '\n';
	}
}

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
