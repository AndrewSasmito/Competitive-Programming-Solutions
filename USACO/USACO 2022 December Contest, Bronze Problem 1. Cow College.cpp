#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, ans1;
ll ans2 = -1;
void solve(){
	cin >> n;

	vector <ll> v(n);
	for (ll &x : v){
		cin >> x;
	}
	
	sort(v.begin(), v.end());

	for (int i = 1; i<=1e6; ++i){
		auto it = lower_bound(v.begin(), v.end(), i);

		ll cur = n - (it - v.begin());
		cur *= i;

		if (cur > ans2){
			ans1 = i, ans2 = cur;
		}
	}
	cout << ans2 << ' ' << ans1 << '\n';
}



int main(){
    ios::sync_with_stdio(0), cin.tie(0);

	solve();
}
