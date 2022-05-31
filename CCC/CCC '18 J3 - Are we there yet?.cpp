#include <bits/stdc++.h>
using namespace std;

int a[5], x;

void solve(){
    for (int i = 1; i<=4; ++i){
        cin >> a[i];
    }
    
    for (int i = 0; i<=4; ++i){
        deque <int> v;
        v.push_back(0);
        int n = i;
        
        while (n > 0){
            v.push_front(v.front() + a[n]);
            --n;
        }
        for (int j = i + 1; j < 5; ++j){
            v.push_back(v.back() + a[j]);
        }
        for (int x : v){
            cout << x << ' ';
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
}
