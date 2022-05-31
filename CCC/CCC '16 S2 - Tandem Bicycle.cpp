#include <bits/stdc++.h>
using namespace std;
 
#define long long ll
#define forloop(i,a,b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
 
 
 
 
vector<int> Dmoj;
vector<int> Peg;
void solve(){
	int question, n;
	cin>>question>>n;
	
	for (int i = 0; i<n; ++i){
		int number; cin>>number;
		Dmoj.push_back(number);
	}
	for (int i = 0; i<n; ++i){
		int input; cin>>input;
		Peg.push_back(input);
	}

	sort(all(Dmoj));
	sort(all(Peg));

	int ans = 0;
	if (question == 1){
		for (int i = 0; i<n; ++i){
			ans += max(Dmoj[i], Peg[i]);
		}
	}else{
		for (int i = 0; i<n; ++i){
			ans += max(Dmoj[i], Peg[n-1-i]);
		}
	}

	cout<<ans;


}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
