#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define forloop(i,a,b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
typedef pair<int, int> pii;
typedef vector<int> vi;


ll cur = 0, pos;
void solve(){
	ll n, m; cin>>n>>m;

	string x;
	for (int i = 0; i<2; ++i){
		getline(cin, x);
	}

	for (int i = 1; i<=m; ++i){
		ll a; cin>>a;
		if (a>cur || (a==cur&&pos<i)){
			cur = a;
			pos = i;
		}
	}
	cur = 0;
	while (true){
		if (pos == 0){
			--n;
			if (n==-1) break;
			if (x[cur] != '0')
				cout<<x[cur];
			++cur;
			if (cur==x.size()) cur = 0;
		}else if (x[cur] == '0'){
			--pos;
			++cur;
			if (cur==x.size()) cur = 0;
		}else{
			++cur;
			if (cur==x.size()) cur = 0;
		}
	}
	cout<<'\n';
	//if i>x.size(), i = 0;
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
