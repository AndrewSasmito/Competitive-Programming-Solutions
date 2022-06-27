#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

string s, t;
void solve(){
	cin >> s >> t;

	if (s.size() != t.size()){
		cout << "NO\n";
		return;
	}
	int pos = -1;
	bool f = 0;
	for (int i = 0; i<s.size(); ++i){
		if (s[i] != t[i]){
			if (f == 1){
				cout << "NO\n";
				return;
			}
			else if (pos >= 0){
				if (s[pos] == t[i] && s[i] == t[pos]){
					f = 1;
					continue;
				}else{
					cout << "NO\n";
					return;
				}
			}else{
				pos = i;
			}
		}
	}
	if (f == 1){
		cout << "YES\n";
	}else{
		cout << "NO\n";
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
