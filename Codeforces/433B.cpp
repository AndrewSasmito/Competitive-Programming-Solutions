#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

ll t1[100001], t2[100001];
ll n, m, l, r, t;
void solve(){
	cin >> n;

	for (int i = 1; i<=n; ++i){
		cin >> t1[i];
		t2[i] = t1[i];
	}

	sort(t2 + 1, t2 + n + 1);

	for (int i = 1; i<=n; ++i){
		t2[i] += t2[i-1];
		t1[i] += t1[i-1];
	}

	cin >> m;
	/*
	for (int i = 1; i<=n; ++i){
		cout << t1[i] << ' ';
	}
	cout << '\n';
	for (int i = 1; i<=n; ++i){
		cout << t2[i] << ' ';
	}
	cout << '\n';
	*/
	for (int i = 0; i<m; ++i){
		cin >> t >> l >> r;

		if (t == 1){
			cout << t1[r] - t1[l-1] << '\n';
		}else{
			cout << t2[r] - t2[l-1] << '\n';
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
