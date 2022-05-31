#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


int n, ans;
void solve(){
	cin>>n;
	
	ans = 1;
	for (int i = 2; i<n; ++i){
		if (n%i == 0)
			ans += i;
	}

	if (ans < n)
		cout<<n<<" is a deficient number.\n";
	else if (ans == n)
		cout<<n<<" is a perfect number.\n";
	else
		cout<<n<<" is an abundant number.\n";
}






int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int testcases = 1;
	cin >> testcases;
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
	

	//Google
	//cout<<"Case #"<<number_of_total_test_cases<<": ";
	// Normal
	solve();
	}
}
