#include <bits/stdc++.h>
using namespace std;
#define ll long long


int n, k, ans = 0, cur, opt;
string s, ans1 = "";
void solve(){
	cin >> n >> k >> s;
	vector <int> gs, hs;
	ans1 = "", ans = 0;

	for (int i = 0; i<n; ++i){
		if (s[i] == 'G'){
			gs.push_back(i);
		}else{
			hs.push_back(i);
		}
		ans1 += '.';
	}

	cur = -1e6;
	for (int i = 0; i<gs.size(); ++i){
		if (cur + k < gs[i]){
			++ans;
			opt = gs[i] + k;
			
			opt = min(opt, n - 1);
			if (ans1[opt] != '.'){
				--opt;
			}
			ans1[opt] = 'G';
			cur = opt;
		}
	}

	cur = -1e6;
	for (int i = 0; i<hs.size(); ++i){
		if (cur + k < hs[i]){
			++ans;
			opt = hs[i] + k;
			
			opt = min(opt, n - 1);
			if (ans1[opt] != '.'){
				--opt;
			}
			ans1[opt] = 'H';
			cur = opt;
		}
	}

	cout << ans << '\n' << ans1 << '\n';
}



int main(){
    ios::sync_with_stdio(0), cin.tie(0);

	int testcases = 1;
	cin >> testcases;

	while (testcases--)
		solve();
}
