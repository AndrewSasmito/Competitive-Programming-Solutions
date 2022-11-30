#include <bits/stdc++.h>

using namespace std;

set <int> s;
int n;
void calc(int x){
    for (int i = 2; i<=x; ++i){
        if (x % i == 0){
            s.insert(i);
            calc(x / i);
            break;
        }
    }
}
void solve(){
    s.clear();
    cin >> n;
    calc(n);
    
    if (s.size() == 3){
        cout << "valid\n";
    }else{
        cout << "not\n";
    }
}

int main() {
    for (int i = 0; i<5; ++i){
        solve();
    }
}
