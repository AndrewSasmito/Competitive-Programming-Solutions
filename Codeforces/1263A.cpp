#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

ll x, ans ;
void solve(){
	vector <ll> v;

	for (int i = 0; i<3; ++i){
		cin >> x;
		v.push_back(x);
	}
	ans = 0;
	sort(v.begin(), v.end());



	if (v[2] < v[0] + v[1]){
		ans = v[2] - v[1];
		v[0] -= ans;

		ans += (v[0] / 2) * 2;


		ans += v[1] - (v[0] / 2);
	}else{
		ans += v[0];

		ans += min(v[1], v[2] - v[0]);
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
	cin >> testcases; 
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
    


    //Google
    //cout<<"Case #"<<number_of_total_test_cases<<": ";
    // Normal
    solve();
    }

	//cout << elapsedTime << '\n';
}
