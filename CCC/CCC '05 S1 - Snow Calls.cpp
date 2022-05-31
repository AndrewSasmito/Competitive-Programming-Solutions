#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n;
string s;
unordered_map <char, char> m;
void solve(){

	m['A'] = '2';
	m['B'] = '2';
	m['C'] = '2';
	m['D'] = '3';
	m['E'] = '3';
	m['F'] = '3';
	m['G'] = '4';
	m['H'] = '4';
	m['I'] = '4';
	m['J'] = '5';
	m['K'] = '5';
	m['L'] = '5';
	m['M'] = '6';
	m['N'] = '6';
	m['O'] = '6';
	m['P'] = '7';
	m['Q'] = '7';
	m['R'] = '7';
	m['S'] = '7';
	m['T'] = '8';
	m['U'] = '8';
	m['V'] = '8';
	m['W'] = '9';
	m['X'] = '9';
	m['Y'] = '9';
	m['Z'] = '9';

	cin >> n;

	while (n--){
		cin >> s;
		int cur = 0;
		for (int i = 0; i<s.size(); ++i){
			if (cur > 11)
				continue;
			if (cur == 3 || cur == 7){
				cout << '-';
				++cur;
			}
			if (s[i] == '-')
				continue;
			if (isalpha(s[i])){
				++cur;
				cout << m[s[i]];
				if (s[i] == 'X'){
					cout << m[s[i]];
				}
			}else{
				++cur;
				cout << s[i];
			}
		}
		cout << '\n';
	}
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
