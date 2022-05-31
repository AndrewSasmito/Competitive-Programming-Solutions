#include <bits/stdc++.h>
using namespace std;

#define ll long long


void solve(){
	int m, n, stroke;
	cin>>m>>n>>stroke;
	vector<bool> paintrow;
	vector<bool> paintcol;

	for (int i = 0; i<m; ++i){
		paintrow.push_back(false);
	}
	for (int i = 0; i<n; ++i){
		paintcol.push_back(false);
	}
	for (int i = 0; i<stroke; ++i){
		char rowcol;
		int num;
		cin>>rowcol>>num;

		if (rowcol == 'R'){
			paintrow[num-1] = not paintrow[num-1];
		}
		else{
			paintcol[num-1] = not paintcol[num-1];
		}
	}

	int ans = 0, goldrow = 0, blackrow = 0;

	for (int i = 0; i<m; ++i){
		if (paintrow[i] == true){
			ans += n;
			++goldrow;
		}else{
			++blackrow;
		}
	}

	for (int i = 0; i<n; ++i){
		if (paintcol[i] == true){
			ans += (blackrow-goldrow);
		}
	}
	cout<<ans;
}












int main(){
	//freopen("speeding.in", "r", stdin);
	//freopen("speeding.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}
