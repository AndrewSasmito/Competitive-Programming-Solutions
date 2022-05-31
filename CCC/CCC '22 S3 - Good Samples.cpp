#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, m, k, num = 0;
vector <ll> ans;
void solve(){
  cin>>n>>m>>k;
  if (k<n){
    cout<<-1<<'\n';
    return;
  }else if ((m*(m+1)/2) + ((n-m)*m)<k){
    cout<<-1<<'\n';
    return;
  }

  bool done = 0;
  ll diff = k-n;
  ll last, count = 0;
  for (int i = 1; i<=n; ++i){

    ++count;

    if (i<=m && i != 1){
      ++num;
    }

    if (done == 1){
      ans.push_back(last);
      continue;
    }

    if (diff-num<0){

      last = ans[(i-1)-(diff+1)];      
      ans.push_back(last);

      done = 1;
    }else if (diff-num == 0){
      if (i<=m){
      last = count;
      ans.push_back(count);
      done = 1;
      }else{

        last = ans[(i-1)-(num+1)];
        ans.push_back(last);
        done = 1;
      }
    }else{

      diff -= num;
      ans.push_back(count);
    }




    if (count==m) count = 0;
  }
    cout<<ans[0];
  for (int i = 1; i<n; ++i){
    cout<<" "<<ans[i];
  }
  cout<<'\n';
}




int main() {
  ios::sync_with_stdio(0);
  cout.tie(0); cin.tie(0);
  solve();
}
