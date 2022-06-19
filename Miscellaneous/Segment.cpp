#include <bits/stdc++.h>
using namespace std;

int n, x, y, ans = 0, cur = 0;
vector <pair<int, int>> v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n;

	for (int i = 0; i<n; ++i){
		cin >> x >> y;
		v.push_back({y, x});
	}
	sort(v.begin(), v.end());

	for (int i = 0; i<v.size(); ++i){
		if (v[i].second >= cur){
			cur = v[i].first;
			++ans;
		}
	}
	cout << ans << '\n';
}
