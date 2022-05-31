#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    
    int coin, f, s, t, ans = 0;
    cin>>coin>>f>>s>>t;

    
    while (true){
        int sam = coin/3;
        f+= sam;
        s+=sam;
        t+=sam;
        ans += sam*3;
        coin-=sam*3;
        
        if (coin>0){
            ++f;
            ++ans;
            --coin;
        }
        if (f>=35){
        f-=35;
        coin+=30;
        }
        
        if (coin>0){
            ++s;
            ++ans;
            --coin;
        }        
        if (s>=100){
        //60
        s-=100;
        coin+=60;
        }
        
        if (coin>0){
            ++t;
            ++ans;
            --coin;
        }        
        if (t>=10){
        //9
        t-=10;
        coin+=9;
        }
        
        
        if (coin == 0) break;
    }

    
    cout<<"Martha plays "<<ans<<" times before going broke.\n";
}
