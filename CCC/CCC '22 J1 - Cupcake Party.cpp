#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    long long r, s;
    cin>>r>>s;
    
    //r * 8 and s*3 and 28 students
    if (r*8 + s*3 < 28) cout<<0<<'\n';
    else cout<<((r*8) + (s*3))-28<<'\n';
}
