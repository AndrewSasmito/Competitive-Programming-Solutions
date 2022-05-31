#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define forloop(i,a,b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MM = 102;
vector <int> mid;
int x[MM], y[MM];
void solve(){
	int n, t; cin>>n>>t;

	for (int i = 1; i<=t; ++i){
		cin>>x[i]>>y[i];
	}

	t+=2;
	x[t]=n+1;
	y[t] = n+1;
	int ans = 0;

	for (int i = 0; i<=t; ++i){
		for (int j = i+1; j<=t; ++j){
			int l = min(x[i], x[j]), r = max(x[i], x[j]);
			int wid = r-l-1;
			
			vector <int> mid = {0, n+1};
			for (int k = 0; k<=t; ++k){
				if (x[k] > l && x[k] < r){
					mid.push_back(y[k]);
				}
			}

			sort (mid.begin(), mid.end());
			for (int k = 1; k<mid.size(); ++k){
				int height = mid[k] -mid[k-1] -1;
				ans = max(ans, min(wid, height));
			}
		}
	}

	cout<<ans<<'\n';
}

 
 
 
 
 
 
 
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int testcases = 1;
	// cin >> testcases;
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){
	    
	// Normal
	solve();
	
	//Google
	//cout<<"Case #"<<number_of_total_test_cases<<": "<<google_answer;
	}
}
