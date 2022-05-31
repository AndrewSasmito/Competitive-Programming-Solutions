#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
int n;
vector <int> v;
void solve(){
	cin >> n;
	
	int l, r;
	for (int i = 0, x; i<n; ++i){
		cin >> x;

		if (x == 1){
			l = i - 1;
			r = i + 1;
		}
		v.push_back(x);
	}

	int sum = 1, ans = 1, mx = 1;
	while (true){
		//cout << l << ' ' << r << '\n';
		if (l == -1 && r == v.size())
			break;
		else if (v[l] < v[r] || r == v.size()){
			
			sum += v[l];
			mx = max(mx, v[l]);
		
			if (sum == (mx * (mx + 1))/2){
				++ans;
			}
			--l;
		}else if (v[r] < v[l] || l == -1){

			sum += v[r];
			mx = max(mx, v[r]);
			if (sum == (mx * (mx + 1))/2){
				++ans;
			}
			++r;
		}
	}
	cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int testcases = 1;
   	//cin >> testcases;
    for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
    

    //Google
    //cout<<"Case #"<<number_of_total_test_cases<<": ";:
    // Normal
    solve();
    }

}
