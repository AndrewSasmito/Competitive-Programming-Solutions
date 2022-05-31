#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;



ll n, a, b, c;
vector <ll> pos;
vector <ll> sec;
vector <ll> dis;

ll searcher (ll x){
	ll tot = 0;
	for (int i = 0; i<n; ++i){
		if (pos[i] > x + dis[i])
			tot += sec[i] * (pos[i] - (dis[i] + x));
		else if (pos[i] < x - dis[i])
			tot += sec[i] * ((x-dis[i]) - pos[i]);
	}
	//cout<<x<<"Score: "<<'\n';
	//cout<<tot<<'\n';
	return tot;
}
void solve(){
	scan(n);
	ll high = 1e9;
	ll low = 0;
	for (int i = 0; i<n; ++i){
		scan(a); scan(b); scan(c);
		
		pos.push_back(a);
		sec.push_back(b);
		dis.push_back(c);
	}
	
	while (low < high){
		ll mid = (low + high)/2;

		ll plus = searcher(mid+1);
		ll neutral = searcher(mid);

		if (neutral>plus)
			low = mid + 1;
		else
			high = mid;
	}
	cout<<searcher(low)<<'\n';

}

 
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int testcases = 1;
	//cin >> testcases;
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
	

	// Normal
	solve();
	//Google
	//cout<<"Case #"<<number_of_total_test_cases<<": "<<google_answer;
	}
}
