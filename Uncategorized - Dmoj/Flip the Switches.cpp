#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
string s;
void solve(){
	cin >> n >> s;

	for (int i = s.size() - 1; i>= 0; --i){
		if (abs((ans % 2) - (s[i] - '0')) == 1){
			++ans;
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

	//cout << elapsedTime << '\n';
}
