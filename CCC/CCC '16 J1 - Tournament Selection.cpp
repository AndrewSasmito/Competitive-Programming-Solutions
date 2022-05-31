#include <bits/stdc++.h>

using namespace std;

int main() {
    int ans;
    for (int i = 0; i<6; ++i){
        char c; cin>>c;
        if (c == 'W')
            ++ans;
    }
    
    if (ans == 0) cout<<-1<<'\n';
    else if (ans <= 2) cout<<3<<'\n';
    else if (ans <= 4) cout<<2<<'\n';
    else cout<<1<<'\n';
}
