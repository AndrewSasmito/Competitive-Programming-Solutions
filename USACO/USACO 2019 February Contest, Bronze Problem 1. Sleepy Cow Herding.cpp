#include <bits/stdc++.h>
using namespace std;

long long n[3], dis = 1000, cur = 0;
int main(){

    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    for (int i = 0; i<3; ++i){
        cin >> n[i];
    }
    sort(n, n + 3);

    if (n[2] - n[1] == 1 && n[1] - n[0] == 1){
        cout << 0 << '\n' << 0 << '\n';
        return 0;
    }

    for (int i = 0; i < 2; ++i){
        dis = min(dis, n[i + 1] - n[i]);
        cur = max(cur, n[i + 1] - n[i]);
    }
    //cout << dis << '\n';
    if (dis == 2){
        cout << 1 << '\n' << cur - 1 << '\n';
    }else{
        cout << 2 << '\n' << cur - 1 << '\n';
    }
}
