#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


int dp[5][5], ans = -1, cur;
bool f = 1;
void solve(){
  //Simple Brute force
	for (int i = 1; i<=4; ++i){
		for (int j = 1; j<=4; ++j){
			cin >> dp[i][j];
		}
	}


	for (int i = 1; i<=4; ++i){
		cur = 0;
		for (int j = 1; j<=4; ++j){
			cur += dp[i][j];
		}
		if (ans == -1){
			ans = cur;
		}else if (ans != cur){
			f = 0;
			break;
		}
	}
	for (int i = 1; i<=4; ++i){
		cur = 0;
		for (int j = 1; j<=4; ++j){
			cur += dp[j][i];
		}
		if (ans == -1){
			ans = cur;
		}else if (ans != cur){
			f = 0;
			break;
		}
	}


	cout << (f == 1 ? "magic" : "not magic") << '\n';
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
