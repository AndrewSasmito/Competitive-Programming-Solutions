#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

void solve(){
	int n; cin>>n;

	int sc = 0, t = 0;
	for (int z = 0; z<=n; ++z){
		string s;
		getline(cin, s);
		for (int i = 0 ;i<=s.size(); ++i){
			if (s[i] == 'S' || s[i] == 's') ++sc;
			else if (s[i] == 'T' || s[i] == 't') ++t;
		}
	}


	cout<<(t>sc?"English":"French")<<'\n';
}


 
 
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testcases = 1;
	//cin >> testcases;
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){
	    
	// Normal
	solve();
	
	//Google
	//cout<<"Case #"<<number_of_total_test_cases<<": "<<google_answer;
	}
}
