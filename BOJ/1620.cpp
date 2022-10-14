#include <bits/stdc++.h>
using namespace std;

int n, m;
string s, x;
unordered_map <string, string> m1, m2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for (int i = 1; i<=n; ++i){
        cin >> s;
        x = to_string(i);
        
        m1[s] = x;
        m2[x] = s;
    }
    
    for (int i = 1; i<=m; ++i){
        cin >> x;
        
        if (m1[m2[x]] == x){
            cout << m2[x] << '\n';
        }else{
            cout << m1[x] << '\n';
        }
    }
}
