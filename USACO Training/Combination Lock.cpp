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
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);
}

unordered_set <int> s;
string x;
int n, t1, t2, t3;
vector <int> v1;
vector <int> v2;
int c;
void solve(){
	usaco();
	cin >> n;

	for (int i = 0; i<3; ++i){
		cin >> c;
		v1.push_back(c);
	}
	for (int i = 0; i<3; ++i){
		cin >> c;
		v2.push_back(c);
	}

	for (int i = v1[0] - 2; i<= v1[0] + 2; ++i){
		for (int j = v1[1] - 2; j<= v1[1] + 2; ++j){
			for (int k = v1[2] - 2; k<= v1[2] + 2; ++k){
				if (i <= 0){
					t1 = i + n;
				}else{
					t1 = i;
				}
				if ( j <= 0){
					t2 = j + n;
				}else{
					t2 = j;
				}

				if (k <= 0){
					t3 = k + n;
				}else{
					t3 = k;
				}

				t1 %= n;
				t2 %= n;
				t3 %= n;
				
				if (t1 == 0){
					t1 = n;
				}
				if (t2 == 0){
					t2 = n;
				}
				if (t3 == 0){
					t3 = n;
				}
				s.insert((t1 * 100) + (t2 * 10) + t3);
			}
		}
	}

	for (int i = v2[0] - 2; i<= v2[0] + 2; ++i){
		for (int j = v2[1] - 2; j<= v2[1] + 2; ++j){
			for (int k = v2[2] - 2; k<= v2[2] + 2; ++k){
				if (i <= 0){
					t1 = i + n;
				}else{
					t1 = i;
				}
				if ( j <= 0){
					t2 = j + n;
				}else{
					t2 = j;
				}

				if (k <= 0){
					t3 = k + n;
				}else{
					t3 = k;
				}

				t1 %= n;
				t2 %= n;
				t3 %= n;
				if (t1 == 0){
					t1 = n;
				}
				if (t2 == 0){
					t2 = n;
				}
				if (t3 == 0){
					t3 = n;
				}

				s.insert((t1 * 100) + (t2 * 10) + t3);

			}
		}
	}
	cout << s.size() << '\n';
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
