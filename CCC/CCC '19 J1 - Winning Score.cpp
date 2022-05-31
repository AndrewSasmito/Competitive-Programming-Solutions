#include <bits/stdc++.h>

using namespace std;
int app = 0, ban = 0, input;
int main() {
    for (int i = 3; i>=1; --i){
        cin>>input;
        app += input*i;
    }
    
    for (int i = 3; i>=1; --i){
        cin>>input;
        ban += input*i;
    }
    
    if (app == ban){
        cout<<'T'<<'\n';
    }else if (app>ban){
        cout<<'A'<<'\n';
    }else{
        cout<<'B'<<'\n';
    }
}
