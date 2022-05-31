#include <bits/stdc++.h>

using namespace std;
int s, m, l;
int main() {
    cin>>s>>m>>l;
    int tot = (1 * s) + (2 * m ) + (3 * l);
    
    cout<<(tot>=10?"happy" : "sad")<<'\n';
}
