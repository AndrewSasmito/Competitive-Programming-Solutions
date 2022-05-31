#include <bits/stdc++.h>
using namespace std;
 
#define long long ll
#define forloop(i,a,b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
 
 
 
 
 
void solve(){
	int n, ans;
	cin>>n;

	if (9== n or n == 10) ans = 1;
	else if (n == 2 or n == 3) ans = 2;
	else if (n == 1) ans = 1;
	else if (n == 7 or n == 8) ans = 2;
	else if (n == 4 or n == 5) ans = 3;
	else{
		ans = 3;
	}
	

	cout<<ans;

}

 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
