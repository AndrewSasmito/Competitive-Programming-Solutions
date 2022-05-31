#include <iostream>

using namespace std;

int fun(int x, int y, int s){
    int mul = s/(x+y);
    int returner = mul*(x-y);
    if (s%(s+y)== 0){
        returner = mul*(x-y);
    }else{
        int tot = mul*(x+y);
        if (s-tot<x){
            returner += (s-tot);
        }else{
            returner -= (s-(tot+x));
        }
    }
    return returner;
}


int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int fi, sec, a, b, c, d, s; cin>>a>>b>>c>>d>>s;
    
    fi = fun(a, b, s);
    sec = fun(c,d,s);
    
    if (fi == sec){
        cout<<"Tied\n";
        return 0;
    }
    
    cout<<(fi>sec?"Nikky\n":"Byron\n");
}
