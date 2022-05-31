#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define forloop(i,a,b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
typedef pair<int, int> pii;
typedef vector<int> vi;

string printer, num;
bool tight = 0, loose = 0;
void solve(){
	string s; cin>>s;
	
	for (int i = 0; i<=s.length(); ++i){

		if (s[i] == '+'){
			//to tighten
			tight = 1;
		}else if (s[i] == '-'){
			//to loosen
			loose = 1;
		}else if ((loose == 1 || tight == 1) && isdigit(s[i]) == true){
			num = num + s[i];
		}else if (loose == 1 &&  isdigit(s[i]) == false){
			cout<<printer<<" loosen "<<num<<'\n';
			num.erase(); printer.erase();
			loose = 0;
			printer += s[i];
		}else if (tight == 1 && isdigit(s[i]) == false){
			cout<<printer<<" tighten "<<num<<'\n';
			num.erase(); printer.erase();
			tight = 0;
			printer += s[i];
		}else{
			printer = printer + s[i];
		}
	}
}

 
 
 
 
 
 
 
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
