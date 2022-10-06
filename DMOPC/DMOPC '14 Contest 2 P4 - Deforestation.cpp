#include <bits/stdc++.h>
using namespace std;

vector <int> v;
int n, q, x, y;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for (int i = 0; i<n; ++i){
        cin >> x;
        v.push_back(x);
    }
    
    for (int i = 1; i<n; ++i){
        v[i] += v[i-1];
    }
    
    cin >> q;
    
    for (int i = 0; i<q; ++i){
        cin >> x >> y;
        
        if (x == 0){
            cout << v[y] << '\n';
        }else{
            cout << v[y] - v[x - 1] << '\n';
        }
    }
}
