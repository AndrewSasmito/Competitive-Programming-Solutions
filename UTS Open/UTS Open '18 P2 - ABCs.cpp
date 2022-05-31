#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int a[4], b[4], c[4];
void solve(){
	for (int i = 1; i<=3; ++i){
		cin>>a[i];
	}
	for (int i = 1; i<=3; ++i){
		cin>>b[i];
	}
	for (int i = 1; i<=3; ++i){
		cin>>c[i];
	}
	
	ll ans = 0;

	if (a[2] == b[3]){
		if (c[3] > 0)
			ans += c[3];
	}if (a[1] == b[2]){
		if (c[2] > 0)
			ans += c[2];

	}if (a[3] == b[1]){
		if (c[1] > 0)
			ans += c[1];

	}
	cout<<ans<<'\n';
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
