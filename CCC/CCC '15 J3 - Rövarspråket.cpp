#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

string s, ans = "";
char c;
vector <char> v = {'a', 'e', 'i', 'o', 'u'};
void solve(){
	cin >> s;

	for (int i = 0; i<s.size(); ++i){
		bool f = 0;

		for (auto x : v){
			if (s[i] == x){
				f = 1;
				break;
			}
		}

		ans += s[i];
		if (f == 1){
			continue;
		}

		int mx = 52;
		for (auto x : v){
			if (abs(s[i] - x) < mx){
				mx = abs(s[i] - x);
				c = x;
			}
		}

		ans += c;
	
		if (s[i] == 'z'){
			ans += 'z';
		}else{
			for (char z = s[i] + 1; z<= 'z'; ++z){
				bool s = 1;

				for (char x : v){
					if (z == x){
						s = 0;
						break;
					}
				}
				if (s == 1){
					ans += z;
					break;
				}
			}
		}
	}
	cout << ans << '\n';
}
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

}
