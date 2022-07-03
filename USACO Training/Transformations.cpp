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
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
}
int n;
char table[11][11], ans[11][11], hold[11][11];




bool oner(){
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            if(ans[j][n-1-i] != table[i][j] ){
                return 0;
            }
        }
    }
    return 1;
}
bool twoer(){
	for (int i = 0; i<n; ++i){
		for (int j = 0; j<n; ++j){
			if (table[i][j] != ans[n - i - 1][n - j - 1]){
				return 0;
			}
		}
	}
	return 1;
}

bool threer(){
	
	for (int i = 0; i<n; ++i){
		for (int j = 0; j<n; ++j){
			if (table[i][j] != ans[n - j - 1][i]){
				return 0;
			}
		}
	}
	return 1;
}

bool fourer(){
	for (int i = 0; i<n; ++i){
		for (int j = 0; j<n; ++j){
			if (table[i][j] != ans[i][n - j - 1]){
				return 0;
			}
		}
	}	
	return 1;
}

bool fiver(){
	for (int i = 0; i<n; ++i){
		for (int j = 0; j<n; ++j){
			hold[i][n - j - 1] = table[i][j];
		}
	}

	bool f = 1;

	for (int i = 0; i<n; ++i){
		for (int j = 0; j<n; ++j){
			if (ans[j][n - i - 1] != hold[i][j]){
				f = 0;
			}
		}
	}

	if (f == 1){
		return 1;
	}
	f = 1;
	for (int i = 0; i<n; ++i){
		for (int j = 0; j<n; ++j){
			if (hold[i][j] != ans[n - i - 1][n - j - 1]){
				f = 0;
			}
		}
	}
	if (f == 1){
		return 1;
	}
	f = 1;
	for (int i = 0; i<n; ++i){
		for (int j = 0; j<n; ++j){
			if (hold[i][j] != ans[n - j - 1][i]){
				return 0;
			}
		}
	}
	return 1;
}


bool sixer(){
	for (int i = 0; i<n; ++i){
		for (int j = 0; j<n; ++j){
			if (table[i][j] != ans[i][j]){
				return 0;
			}
		}
	}
	return 1;
}
void solve(){
	usaco();
	cin >> n;
	for (int i = 0; i<n; ++i){
		for (int j = 0; j<n; ++j){
			cin >> table[i][j];
		}
	}
	for (int i = 0; i<n; ++i){
		for (int j = 0; j<n; ++j){
			cin >> ans[i][j];
		}
	}
	
	if (oner()){
		cout << 1 << '\n';
	}else if (twoer()){
		cout << 2 << '\n';
	}else if (threer()){
		cout << 3 << '\n';
	}else if (fourer()){
		cout << 4 << '\n';
	}else if (fiver()){
		cout << 5 << '\n';
	}else if (sixer()){
		cout << 6 << '\n';
	}else{
		cout << 7 << '\n';
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
	//cin >> testcases; 
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
    


    //Google
    //cout<<"Case #"<<number_of_total_test_cases<<": ";
    // Normal
    solve();
    }

	//cout << elapsedTime << '\n';
}
