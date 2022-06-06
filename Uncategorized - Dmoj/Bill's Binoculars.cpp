#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MM = 5e5 + 1;
int n, k, a, b, c;
ll dp[MM], ans[MM], printer = 0;
void solve(){
	cin >> n >> k;

	for (int i = 0; i<k; ++i){
		cin >> a >> b >> c;
		
		if (ans[a] < c){
			printer += c - ans[a];
			dp[a] += c - ans[a];
			ans[a] = 0;
		}else{
			ans[a] -= c;
		}
		ans[b] += c;
	}

	cout << printer << '\n';

	for (int i = 1; i<=n; ++i){
		cout << dp[i] << ' ';
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
