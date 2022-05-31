#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

string s;
void solve(){
	cin >> s;

	int lcnt = 0, mcnt = 0, scnt = 0;

	for (int i = 0; i<s.size(); ++i){
		if (s[i] == 'L')
			++lcnt;
		else if (s[i] == 'M')
			++mcnt;
		else
			++scnt;
	}

	int MinL = 0, SinL = 0, LinM = 0, SinM = 0, LinS = 0, MinS = 0;

	for (int i = 0; i<s.size(); ++i){
		if (s[i] != 'L' && i <lcnt){
			if (s[i] == 'M')
				++MinL;
			else
				++SinL;
		}else if (s[i] != 'M' && lcnt <= i && i < lcnt + mcnt){
			if (s[i] == 'L')
				++LinM;
			else
				++SinM;
		}else if (s[i] != 'S' && lcnt + mcnt <= i){
			if (s[i] == 'L')
				++LinS;
			else
				++MinS;
		}
	}

	//cout << MinL << ' ' << SinL << ' ' << LinM << ' ' << SinM << ' ' << LinS << ' ' << MinS << '\n';

	int ans = 0, calc = 0;

	calc = min(MinL, LinM);
	MinL -= calc;
	LinM -= calc;

	ans += calc;


	calc = min(SinL, LinS);
	SinL -= calc;
	LinS -= calc;

	ans += calc;
	
	calc = min(SinM, MinS);
	SinM -= calc;
	MinS -= calc;

	ans += calc;

	calc = 0;
	calc += MinL + SinL + LinM + SinM + LinS + MinS;

	ans += (calc/3) * 2;

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
