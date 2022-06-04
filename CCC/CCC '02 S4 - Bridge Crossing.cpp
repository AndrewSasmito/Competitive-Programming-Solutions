#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int m, q, x, dp[101], tim[101], group[101];
string v[101];
string s;
void solve(){

	cin >> m >> q;

	for (int i = 1; i<=q; ++i){
		cin >> v[i] >> tim[i];
	}

	for (int i = 1; i<=q; ++i){ dp[i] = 100000; group[i] = -1;}

	for (int i = 0; i<=q; ++i){
		int cur = 0;

		for (int j = 1; j<=m && i + j - 1 < q; ++j){
			cur = max(cur, tim[i + j]);

			if (dp[i] + cur < dp[i + j]){
				dp[i + j] = dp[i] + cur;
				group[i + j] = j;
			}
		}
	}

	cout << "Total Time: " << dp[q] << '\n';

	vector <int> ans;

	int z;
	for (z = q; z>=1; ){
		ans.push_back(group[z]);

		z -= group[z];
	}

	int cnt = 0, pos = ans.size() - 1;

	for (int i = 1; i<=q; ++i){
		++cnt;
		cout << v[i] << ' ';

		if (ans[pos] == cnt){
			cout << '\n';
			--pos;
			cnt = 0;
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
