#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, cur = 0, ans = 0, last, tot, cx;
ll x;
vector <ll> v;
int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);


    cin >> n;

    for (int i = 0; i<n; ++i){
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i<n; ++i){
        cur = 0;
        tot = 0;
        x = 1;
        last = v[i];
        cx = v[i];
        for (int j = i + 1; j<n; ++j){
            if (v[j] <= last + x){
                ++tot;
                cx = v[j];
            }else if (v[j] <= cx + x + 1 && cx != last){
                ++x;
                ++tot;
                last = v[j];
                cx = v[j];
            }else{
                break;
            }
        }
        
        cur += tot;
        tot = 0;
        last = v[i];
        cx = v[i];
        x = 1;
        for (int j = i - 1; j>=0; --j){
            if (v[j] >= last - x){
                ++tot;
                cx = v[j];
            }else if (v[j] >= cx - x - 1 && cx != last){
                ++x;
                ++tot;
                last = v[j];
                cx = v[j];
            }else{
                break;
            }
        }

        cur += tot;
        ans = max(ans, cur);
    }
    cout << ans + 1 << '\n';
}
