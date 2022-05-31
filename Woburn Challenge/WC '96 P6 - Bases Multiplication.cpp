#include <bits/stdc++.h>
using namespace std;


#define ll long long
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

int b1, b2, b3;
string a, b;
void solve(){
	cin >> a >> b1 >> b >> b2 >> b3;


	int ans1 = 0, ans2 = 0;
	for (int i = 0; i<a.size(); ++i){
		ans1 += (a[a.size() - 1 - i] - '0') * pow(b1, i);
	}
	for (int i = 0; i<b.size(); ++i){
		ans2 += (b[b.size() - 1 - i] - '0') * pow(b2, i);
	}
	ans1 *= ans2;

	string ans = "";
	while (ans1 > 0){
		ans += to_string(ans1%b3);
		ans1 /= b3;
	}

	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int testcases = 5;
    //cin >> testcases;
    for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
    

    //Google
    //cout<<"Case #"<<number_of_total_test_cases<<": ";:
    // Normal
    solve();
    }

}
