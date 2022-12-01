#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll x;
vector <ll> v;
void solve(){
  cin >> n;
  bool f = 0, s = 0;
  for (int i = 0; i<n; ++i){
    cin >> x;
    v.push_back(x);
    if (x%2 == 0)
      f = 1;
    else
      s = 1;
  }
  if (f == 1 && s == 1 && n == 2){
    cout << 1 << '\n';
    return;
  }

  sort(v.begin(), v.end());
  for (int i = 0; i<n - 1; ++i){
    for (int j = i + 1; j<n; ++j){
      auto it = lower_bound(v.begin(), v.end(), ((v[i] + v[j])/2));
      if (*it == (v[i] + v[j])/2 && (v[i] % 2 == v[j] % 2)){
        cout << 3 << '\n';
        return;
      }
    }
  }
  cout << 2 << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int testcases = 1;
  //cin >> testcases;
  for (int i = 1; i<=testcases; ++i){
    solve();
  }
}
