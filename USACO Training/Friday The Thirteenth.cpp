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
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);
}

//do not submit if usaco(); is open
int n, day = 0, dp[8];
string s;
void solve(){
	usaco();
	cin >> n;


	for (int i = 0; i<n; ++i){
		
		for (int j = 1; j<=12; ++j){
			day += 13;
			day %= 7;
			
			++dp[day];

			if (j == 4 || j == 6 || j == 9 || j == 11){
				day += (30 - 13);
			}else if (j == 2){
				s = to_string(1900 + i);

				if (s[s.size() - 1] == '0' && s[s.size() - 2] == '0'){
					if ((1900 + i) % 400 == 0){
						day += (29 - 13);
					}else{
						day += (28 - 13);
					}
				}else if ((1900 + i) % 4 == 0){
					day += (29 - 13);
				}else{
					day += (28 - 13);
				}
			}else{
				day += (31 - 13);
			}
		}
	}
	cout << dp[6];
	for (int i = 1; i<7; ++i){
		cout << ' ' << dp[(6 + i) % 7];
	}
	cout << '\n';
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
