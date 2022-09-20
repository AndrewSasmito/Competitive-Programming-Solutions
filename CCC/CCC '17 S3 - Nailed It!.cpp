#include <bits/stdc++.h>
using namespace std;

int n, x, cnt[2001], tot[4002];
int main(){
    cin >> n;


    for (int i = 0; i<n; ++i){
        cin >> x;
        ++cnt[x];
    }

    for (int i = 1; i<=2000; ++i){
        if (cnt[i] == 0){
            continue;
        }
        for (int j = i; j<=2000; ++j){
            if (cnt[j] == 0){
                continue;
            }
            if (i == j){
                tot[i + i] += (cnt[i] / 2);
            }else{
                tot[i + j] += (cnt[i] + cnt[j]) / 2;
            }
            //cout << i << ' ' << j << ' ' << tot[i+j] << ' ' << (cnt[i] + cnt[j]) / 2 << '\n';
        }
    }

    int ans1 = -1, ans2 = 1;

    for (int i = 1; i<=4000; ++i){
        if (tot[i] > ans1){
            ans1 = tot[i];
            ans2 = 1;
        }else if (tot[i] == ans1){
            ++ans2;
        }
    }

    cout << ans1 << ' ' << ans2 << '\n';
}
