#include <bits/stdc++.h>
using namespace std;

int n, x, ans = 0;
int main(){
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    cin >> n;
    vector <int> v;
    unordered_map <int, bool> m;
    for (int i = 1; i<=n; ++i){
        v.push_back(i);
    }

    int cur = 0;

    for (int i = 1; i<=n; ++i){
        cin >> x;

        while (m[v[cur]] == 1){
            ++cur;
        }
        if (v[cur] != x){
            ans = i;
        }else{
            ++cur;
        }
        m[x] = 1;
    }

    cout << min(ans, n - 1) << '\n';
}
