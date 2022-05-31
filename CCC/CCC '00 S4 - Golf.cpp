#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define forloop(i,a,b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dp [99999];
void solve(){
	int n, w;
	cin>>n>>w;

	fill(begin(dp), end(dp), 5281);

	dp[0] = 0;

	int club[w];

	for (int i = 0; i<w; ++i){
		int num;
		cin>>num;
		club[i] = num;
	}

	for (int i = 0; i<n+1; ++i){
		for (int j = 0; j<w; ++j){
			if (club[j]>i) continue;

			dp[i] = min(dp[i - club[j]] + 1, dp[i]);
		}
	}


	if (dp[n] == 5281){
		cout<<"Roberta acknowledges defeat."<<"\n";
	}else{
		cout<<"Roberta wins in "<<dp[n]<<" strokes."<<"\n";
	}
}


 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
