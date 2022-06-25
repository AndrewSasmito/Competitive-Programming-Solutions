#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

double n, x, y, dis, s, ans = 0;
vector <pair<double, double>> v;
void solve(){
	cin >> n;

	for (int i = 0; i<n; ++i){
		cin >> x >> y;
		v.push_back({x, y});
	}

	sort(v.begin(), v.end(), greater<pair<double, double>>());

	dis = v[0].first;
	s = v[0].second;

	for (int i = 1; i<v.size(); ++i){
		ans += (dis - v[i].first) / s;

		dis = v[i].first;

		if (v[i].second > s){
			s = v[i].second;
		}
	}
	ans += (dis - 0) / s;

	printf("%.5f\n", ans);
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
