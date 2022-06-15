#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int k, n, x, pos[11][21];
const int X = 131;
unordered_set<ll> s;
void inserter(int a, int b){
	ll num = 0;
	//cout << a << ' ' << b << '\n';

	if (a > b){
		swap(a, b);
	}

	num += (a * X * X) + (b * X);
	
	s.insert(num);	
}
void checker(int i, int j){
	bool f = (pos[1][i] < pos[1][j]);


	for (int z = 2; z <=k; ++z){
		if (pos[z][i] > pos[z][j] && f == 1){
			return;
		}else if (pos[z][i] < pos[z][j] && f == 0){
			return;
		}
	}
	inserter(i, j);
}
void solve(){
	cin >> k >> n;
	for (int i = 1; i<=k; ++i){
		for (int j = 1; j <=n; ++j){
			cin >> x;
			pos[i][x] = j;
		}
	}

	for (int i = 1; i<=n; ++i){
		for (int j = i+1; j<=n; ++j){
			checker(i, j);
		}
	}
	cout << s.size() << '\n';
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
