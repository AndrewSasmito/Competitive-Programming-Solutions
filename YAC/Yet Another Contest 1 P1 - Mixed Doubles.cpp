#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define forloop(i,a,b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
typedef pair<int, int> pii;
typedef vector<int> vi;
 

ll ans = 0;
		ll diff = 0;
vector <ll> boys;
vector <ll> girls;
void solve(){
	ll n, k; cin>>n>>k;
	ll orig = k;
	for (ll i = 1; i<=n; ++i){
		ll input; cin>>input;
		boys.push_back(input);
	}
	for (ll i = 1; i<=n; ++i){
		ll input; cin>>input;
		girls.push_back(input);
	}


	sort(all(boys));
	sort(all(girls));
	if (k == 0){
		for (ll i = 0; i<=n; ++i){
			ans += boys[i]*girls[i];
			ans %= 1000000000 + 7;
		}
		cout<<ans<<"\n";
		return;
	}
	bool boy = 0;
	if (boys[n-1]>girls[n-1]){
		diff = boys[n-1] - girls[n-1];
		boy = 1;
	}else if (boys[n-1]<girls[n-1]){
		diff = girls[n-1] - boys[n-1];
		boy = 0;
	}
	k -= diff;
	ll div;
	if (k<=0) div = -1;
	else if (k%2 == 0) div = 1;
	else div = 0;

	if (boys[n-1] == girls[n-1]){
		if (div == 1) ans += (boys[n-1] + k/2) * (girls[n-1] + k/2);
		else ans += (boys[n-1] + k/2 + 1) * (girls[n-1] + k/2);
	}else if (div == -1){
		if (boy == 1){
			ans += (girls[n-1] + orig) * (boys[n-1]);
		}else{
		ans += (boys[n-1] + orig) * (girls[n-1]);
		}
	}else{
		if (boy == 1 and div == 1) ans += (girls[n-1] + diff + k/2) * (boys[n-1] + k/2);
		else if (boy == 1 and div == 0) ans += (girls[n-1] + diff + k/2 + 1) * (boys[n-1] + k/2);
		else if (boy == 0 and div == 1) ans += (boys[n-1] + diff + k/2) * (girls[n-1] + k/2);
		else ans += (boys[n-1] + diff + k/2 + 1) * (girls[n-1] + k/2);	
	}
	for (ll i = 0; i<n-1; ++i){
		ans += boys[i] * girls[i];
		ans %= 1000000000 + 7;
	}
	cout<<ans<<"\n";
}

 

 
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
