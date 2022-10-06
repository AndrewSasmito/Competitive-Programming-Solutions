#include <bits/stdc++.h>
using namespace std;

int n, m, x, cnt;
int main(){
    cin >> n;
    
    for (int i = 1; i<=n; ++i){
        cin >> m;
        cnt = 0;
        
        for (int j = 0; j<m; ++j){
            cin >> x;
            cnt += x;
        }
        if (cnt > 0)
            cout << "Day " << i << ": " << cnt << '\n';
        else
            cout << "Weekend\n";
    }
}
