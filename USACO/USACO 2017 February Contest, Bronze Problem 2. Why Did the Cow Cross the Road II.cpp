#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector <int> v[27];
string s;

void usaco(){
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);
}

void solve(){
    usaco();
    cin >> s;

    for (int i = 0; i < s.size(); ++i){
        v[s[i] - 'A'].push_back(i);
    }

    for (int i = 0; i < 26; ++i){
        for (int j = 0; j < 26; ++j){
            if (i == j)
                continue;

            ans += (v[i][0] < v[j][0] && v[j][0] < v[i][1] && v[j][1] > v[i][1]);
        }
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    //cin >> t;

    while (t--){
        solve();
    }
}
