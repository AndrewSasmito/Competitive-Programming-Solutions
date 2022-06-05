#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


int n, x;
vector <int> v;
bool pos[200001];
void solve(){
	cin >> n;

	for (int i = 0; i<n; ++i){
		cin >> x;
		v.push_back(x);
		pos[x] = 1;
	}

	sort(v.begin(), v.end());

	int ans = 0;

	//brute force? N^2 time complexity is possible in 1.4 seconds
	
	for (int i = 0; i<v.size() - 2; ++i){
		for (int j = i + 1; j <v.size() - 1; ++j){
			int diff = v[j] - v[i];
			if (diff == 0)
			    continue;
			if (pos[v[j] + diff] == 1){
				ans = max(ans, v[j] + v[i] + diff + v[j]);
			}
		}
	}
	cout << ans << '\n';
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
