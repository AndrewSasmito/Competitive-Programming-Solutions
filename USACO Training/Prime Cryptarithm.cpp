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
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);
}

int n, ans = 0, c, d, a1, a2;
char x;
vector <char> v;
set <pair<string, string>> setter;
string a, b, st1, st2;
bool check(string s){
	for (int i = 0; i<s.size(); ++i){
		bool f = 0;
		for (int j = 0; j<n; ++j){
			if (s[i] == v[j]){
				f = 1;
				break;
			}
		}
		if (f == 0){
			return 0;
		}
	}
	return 1;
}

void solve(){
	usaco();
	cin >> n;

	for (int i = 0; i<n;  ++i){
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i<n; ++i){
		for (int j = 0; j<n; ++j){
			for (int k = 0; k < n; ++k){
				for (int x = 0; x < n; ++x){
					for (int y = 0; y < n; ++y){
						
						b = v[i];
						b += v[j];
						b += v[k];
						
						d = stoi(b);
						
						a1 = d * (v[x] - '0');
						a2 = d * (v[y] - '0');
						st2 = to_string(a1);
						st1 = to_string(a2);
						if (st2.size() != 3 || st1.size() != 3)
							continue;

						if (check(to_string(a1)) == 1 && check(to_string(a2)) == 1){
							st1 = to_string(a2 + (a1* 10));
							if (check(to_string(a2 + (a1 * 10))) == 1 && st1.size() == 4){

								st1 = v[x];
								st1 += v[y];

								st2 = v[i];
								st2 += v[j];
								st2 += v[k];
								//cout << a2 + (a1 * 10)  << ' ' << st1 << ' ' << st2 << '\n';
								setter.insert({st2, st1});
							}
						}
					}
				}
			}
		}
	}
	cout << setter.size() << '\n';
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
