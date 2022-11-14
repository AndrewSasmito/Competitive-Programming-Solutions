#include <bits/stdc++.h>
using namespace std;

int n, x;
vector <int> ans;
int main(){
    cin >> n;
    
    for (int i = 0; i<n; ++i){
        cin >> x;
        
        vector <int> :: iterator pos;
        
        pos = lower_bound(ans.begin(), ans.end(), x);
        
        if (pos == ans.end()){
            ans.push_back(x);
        }else{
            ans[pos - ans.begin()] = x;
        }
    }
    cout << ans.size() << '\n';
}
