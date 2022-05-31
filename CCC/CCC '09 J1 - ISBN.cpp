#include <bits/stdc++.h>
using namespace std;

int ans = 91;
int f, s, t;
void solve(){
  cin >> f >> s >> t;

  cout << "The 1-3-sum is " << ans + f + (s * 3) + t << '\n';
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
