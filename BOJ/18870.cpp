#include <bits/stdc++.h>
using namespace std;

int n, x;
set <int> s;
vector <int> z, v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for (int i = 0; i<n; ++i){
        cin >> x;
        s.insert(x);
        z.push_back(x);
    }
    for (int x : s){
        v.push_back(x);
    }

    
    for (int i = 0; i<n; ++i){
        int lo = 0, hi = v.size();
        while (lo < hi){
            int mid = (lo + hi) / 2;
        
            if (v[mid] >= z[i]){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        
        cout << hi << ' ';
    }
}
