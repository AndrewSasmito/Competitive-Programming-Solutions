#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, p, ans = 0, x;
multiset <int, greater <int> > s;
void solve(){
	scan(n); scan(p);

	for (int i = 0; i<=n; ++i){
		s.insert(i);
	}
	bool f = 0;
	int it = 0;
	for (int i = 0; i<p; ++i){
		scan(x);
		
		it = *s.lower_bound(x);
		
		if (f == 1)
			continue;
		else if (it == 0){
			f = 1;
			continue;
		}
		s.erase(it);
		++ans;
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
