#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
    cin >> n;

    if (n < 4){
        cout << 0 << '\n';
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < n - 3; ++i){
        for (int j = i + 1; j < n-2; ++j){
            for (int k = j + 1; k < n-1; ++k){
                ++cnt;
            }
        }
    }
    cout << cnt << '\n';
}
