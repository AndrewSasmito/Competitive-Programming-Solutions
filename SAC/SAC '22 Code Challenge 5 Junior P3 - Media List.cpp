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
int n, q, f, ss;
string s;
vector <int> check[500001];
unordered_map <string, int> m;
void solve(){
	cin >> n >> q;

	int cur = 1;
	for (int i = 0; i<q; ++i){
		cin >> f >> ss >> s;
		if (f == 2){
			if (m.find(s) == m.end()){
				m[s] = cur;
				++cur;
			}
			check[m[s]].push_back(ss);

		}else{
			if (m.find(s) == m.end()){
				cout << 0 << '\n';
				continue;
			}else{
				sort(check[m[s]].begin(), check[m[s]].end());
				auto it = lower_bound(check[m[s]].begin(), check[m[s]].end(), ss);

				if (*it == ss)
					cout << 1 << '\n';
				else
					cout << 0 << '\n';
			}
		}
	}
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
