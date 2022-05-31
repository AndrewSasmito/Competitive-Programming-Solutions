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
int n;
char c;
string s;
const int X = 13;
unordered_map <int, char> m;
void solve(){
	cin >> n;

	for (int i = 0; i<n; ++i){
		cin >> c >> s;

		int cnt = 0;
		for (int i = 0; i<s.size(); ++i){
			cnt *= X;
			cnt += s[i];
		}
		m[cnt] = c;
	}

	cin >> s;
	int cnt = 0;
	for (int i = 0; i<s.size(); ++i){
		cnt *= X;
		cnt += s[i];

		if (m.find(cnt) != m.end()){
			cout << m[cnt];
			cnt = 0;
		}
	}
	cout << '\n';
}
int main(){
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
