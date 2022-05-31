#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, ans = 0; cin>>n;
    
    for (int i = 0, point, pen, tot; i<n; ++i){
        cin>>point>>pen;
        tot = (point*5) - (pen*3);
        if (tot > 40) ++ans;
    }
    
    if (ans == n) cout<<ans<<"+\n";
    else cout<<ans<<'\n';
}
