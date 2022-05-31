#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

void solve(){
	int n;
	cin>>n;

	string s;
	cin>>s;
	
	int acnt = 0, bcnt = 0;
	for (int i = 0; i<n; ++i){
		if (s[i] == 'A')
			++acnt;
		else
			++bcnt;
	}

	if (acnt == bcnt)
		cout<<"Tie\n";
	else if (acnt > bcnt)
		cout<<"A\n";
	else
		cout<<"B\n";
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
