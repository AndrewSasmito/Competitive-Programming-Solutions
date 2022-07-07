#include <bits/stdc++.h>

using namespace std;
vector <long long> v;
long long x;
int n;
int main() {
    cin >> n;
    
    for (int i = 0; i<n; ++i){
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    
    for (long long x : v){
        cout << x << ' ';
    }
    cout << '\n';
}
