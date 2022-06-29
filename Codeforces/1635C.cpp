#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n;
ll x;
bool sorted(vector <ll> &v){
	for (int i = 1; i<v.size(); ++i){
		if (v[i] < v[i-1]){
			return 0;
		}
	}
	return 1;
}
void solve(){
	vector <ll> v;

	cin >> n;

	for (int i = 0; i<n; ++i){
		cin >> x;
		v.push_back(x);
	}

	if (v[n-1] < v[n-2]){
		cout << -1 << '\n';
		return;
	}else if (sorted(v)){
		cout << 0 << '\n';
		return;
	}else if (!sorted(v) && v[n-1] < 0){
		cout << -1 << '\n';
		return;
	}

	cout << n - 2 << '\n';

	for (int i = n - 2; i>0; --i){
		cout << i << ' ' << n - 1 << ' ' << n << '\n';
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


    int testcases = 1;
	cin >> testcases; 
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
    


    //Google
    //cout<<"Case #"<<number_of_total_test_cases<<": ";
    // Normal
    solve();
    }

	//cout << elapsedTime << '\n';
}
