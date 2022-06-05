#include <bits/stdc++.h>

using namespace std;


vector <int> ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    
    while (n--){
        int input; cin>>input;
        ans.push_back(input);
    }
    
    sort(ans.begin(), ans.end());
    
    for (int x: ans){
        cout<<x<<'\n';
    }
}
