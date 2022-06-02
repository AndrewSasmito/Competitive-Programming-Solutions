#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, m, x;
bool dp[101];
void solve(){
	cin >> n >> m;


	for (int i =0; i<m; ++i){
		cin >> x;
		int cnt = 0;

		for (int j = 1; j<=n; ++j ){
			if (dp[j] == 0)
				++cnt;

			if (cnt == x){
				cnt = 0;
				dp[j] = 1;
			}
		}
	}

	for (int i = 1; i<=n; ++i){
		if (dp[i] == 0){
			cout << i << '\n';
		}
	}
}
	
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
