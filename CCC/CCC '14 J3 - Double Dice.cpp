#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

void solve(){
	int n;
	cin>>n;
	
	int x, y;
	int ans1 = 100, ans2 = 100;

	for (int i = 0; i<n; ++i){
		cin>>x>>y;

		if (x > y)
			ans2 -= x;
		else if (x < y)
			ans1 -= y;
	}

	cout<<ans1<<'\n'<<ans2<<'\n';
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
