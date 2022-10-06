#include <bits/stdc++.h>
using namespace std;

string s, x;
int ans = 0, n;
int main(){
    cin >> s >> n;
    
    for (int i = 0; i<n; ++i){
        cin >> x;
        
        ans += (s == x);
    }
    cout << ans << '\n';
}
