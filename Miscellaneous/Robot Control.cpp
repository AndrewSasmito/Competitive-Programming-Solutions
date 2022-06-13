#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

vector <int> v1;
vector <int> v2;
int n, m, x;
void solve(){
	cin >> n >> m;

	for (int i = 0; i<m; ++i){
		cin >> x;
		v1.push_back(x);
	}
	sort(v1.begin(), v1.end());

	for (int i = 1; i<m; ++i){
		v2.push_back(v1[i] - v1[i-1]);
	}
	sort(v2.begin(), v2.end());
	int ans = 0;
	for (int i = 0; i< m - n; ++i){
		ans += v2[i];
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
