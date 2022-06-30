#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

void usaco(){
	freopen("cowsignal.in", "r", stdin);
	freopen("cowsignal.out", "w", stdout);
}

//do not submit if usaco(); is open
string s;
int m, n, k;
void solve(){
	cin >> m >> n >> k;


	for (int i = 0; i<m; ++i){
			cin >> s;

			//enlarger


			for (int x = 0; x < k; ++x){
				for (int z = 0; z < n; ++ z){
					for (int y = 0; y < k; ++y){
						cout << s[z];
					}
				}
				cout << '\n';
			}

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

	usaco();


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
