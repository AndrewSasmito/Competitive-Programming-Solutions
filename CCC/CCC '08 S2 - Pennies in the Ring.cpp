#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    while (true){
        int n; cin>>n;
		double radius;
        if (n == 0) return;
        
        ll counter = 0;
        radius = n*n;
        for (int i = 0; i<=n; ++i){
            counter = counter + sqrt(radius - (double) i*i);
        }
        ll ans = counter*4 + 1;
        cout<<ans<<'\n';
    }
}





 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
