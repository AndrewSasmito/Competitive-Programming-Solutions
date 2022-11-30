#include <bits/stdc++.h>
using namespace std;

int n, m, c;
long long ans = 0;

bool calc(long long x, vector <long long> &v){
    int cur = 1, hold = 1;
    long long pos = v[0];
    for (int i = 1; i<v.size(); ++i){
        if (v[i] - pos > x || hold == c){
            pos = v[i], ++cur, hold = 1;

            if (cur > m){
                return 0;
            }
        }else{
            ++hold;
        }
    }
    return 1;
}

void solve(){
    cin >> n >> m >> c;
    vector <long long> v(n);
    for (int i = 0; i<n; ++i){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    long long lo = 0, hi = 1e9;

    while (lo < hi){
        long long mid = (lo + hi) / 2;

        if (calc(mid, v)){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }
    cout << hi << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
}
