#include <bits/stdc++.h>
using namespace std;
#define ll long long
double a, b, c;

void solve(){
  cin >> a >> b >> c;

  double ans1 = 0, ans2 = 0;

  ans1 += (max((double)0, a - (double)100) * 25) + (b * 15) + (20 * c);
  ans2 += (max((double)0, a - (double)250) * 45) + (b * 35) + (c * 25);

  cout << "Plan A costs " << ans1/100 << '\n';


  cout << "Plan B costs " << ans2/100 << '\n';

  if (ans1 == ans2){
    cout << "Plan A and B are the same price.\n";
  }else if (ans1 < ans2){
    cout << "Plan A is cheapest.\n";
  }else{
    cout << "Plan B is cheapest.\n";
  }
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
