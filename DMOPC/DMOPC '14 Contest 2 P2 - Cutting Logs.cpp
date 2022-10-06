#include <bits/stdc++.h>
using namespace std;

vector <int> v;
int cnt = 0, n;
string s;
int main(){
    cin >> n >> s;
    
    for (int i = 0; i < n; ++i){
        if (s[i] == 'X'){
            if (cnt > 0){
                v.push_back(cnt);
            }
            cnt = 0;
        }else{
            ++cnt;
        }
    }
    if (cnt > 0){
        v.push_back(cnt);
    }
    
    cout << v.size() << '\n';
    
    for (int x : v){
        for (int i = 0; i < x; ++i){
            cout << 'O';
        }
        cout << '\n';
    }
}
