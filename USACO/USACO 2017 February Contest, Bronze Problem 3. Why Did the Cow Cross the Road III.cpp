#include <bits/stdc++.h>
using namespace std;
int n, x, y, ans = 0;
vector <pair<int, int>> v;

void printer(){
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    printer();

    cin >> n;

    for (int i = 0; i<n; ++i){
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());

    for (auto m : v){
        if (m.first > ans){
            ans = m.first + m.second;
        }else{
            ans += m.second;
        }
    }
    cout << ans << '\n';
}
