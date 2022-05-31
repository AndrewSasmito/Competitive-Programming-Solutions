#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

string s, t;
int pos = 0;
void solve(){
	getline(cin, t);
	getline(cin, s);

	for (int i = 0; i<s.size(); ++i){
		if (isalpha(s[i]) == 0)
			continue;
		if (pos == t.size())
			pos = 0;
		char cur = t[pos] - 'A';
		if (s[i] + cur > 'Z'){
		    cout << (char)(s[i] + cur - 26);
		}else
		    cout << (char)(s[i] + cur);
		++pos;
	}
	cout << '\n';
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
