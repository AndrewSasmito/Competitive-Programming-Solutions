#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define forloop(i,a,b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
typedef pair<int, int> pii;
typedef vector<int> vi;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

//3 lowercase, 2 uppercase, 1 digit
void solve(){
	int lc = 0, uc = 0, dig = 0;
	string s;
	cin>>s;
	if (s.size()<8 || s.size()>12){
		cout<<"Invalid\n";
		return;
	}

	for (int i = 0; i<s.size(); ++i){
		if (isdigit(s[i])) ++dig;
		else if (islower(s[i])) ++lc;
		else if (isupper(s[i])) ++uc;
	}

	if ((lc>=3 && uc>=2) && dig>=1) cout<<"Valid\n";
	else cout<<"Invalid\n";
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
