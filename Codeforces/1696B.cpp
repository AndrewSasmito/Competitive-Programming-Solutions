#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, cnt;
ll x;
void solve(){
	cin >> n;
	vector <ll> v;

	cnt = 0;


	for (int i = 0; i<n; ++i){
		cin >> x;
		cnt += (x == 0);
		v.push_back(x);
	}

	if (cnt == n){
		cout << 0 << '\n';
		return;
	}

	int l = 0, r = n - 1;

	while (true){
		if (v[l] > 0){
			break;
		}
		++l;
	}


	while (true){
		if (v[r] > 0){
			break;
		}
		--r;
	}

	for (int i = l; i<=r; ++i){
		if (v[i] == 0){
			cout << 2 << '\n';
			return;
		}
	}

	cout << 1 << '\n';
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
