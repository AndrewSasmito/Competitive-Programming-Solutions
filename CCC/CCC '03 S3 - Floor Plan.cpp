#include <bits/stdc++.h>
using namespace std;

int n, x, y, ans = 0;
queue <pair<pair<int, int>, int>> q;
vector <int> v;
bool vis[27][27];
char dp[27][27];

int calc(){
    int ret = 0;

    while (q.size()){
        int fx = q.front().first.first;
        int fy = q.front().first.second;

        int dis = q.front().second;
        q.pop();
        ++ret;

        if (fy != y - 1 && vis[fx][fy + 1] == 0){
            q.push({{fx, fy + 1}, dis + 1});
            vis[fx][fy + 1] = 1;
        }if (fy != 0 && vis[fx][fy - 1] == 0){
            q.push({{fx, fy - 1}, dis + 1});
            vis[fx][fy - 1] = 1;
        }if (fx != x - 1 && vis[fx + 1][fy] == 0){
            q.push({{fx + 1, fy}, dis + 1});
            vis[fx + 1][fy] = 1;
        }if (fx != 0 && vis[fx - 1][fy] == 0){
            q.push({{fx - 1, fy}, dis + 1});
            vis[fx - 1][fy] = 1;
        }
    }
    return max(ret, 1);
}

void solve(){
    cin >> n >> x >> y;

    for (int i = 0; i<x; ++i){
        for (int j = 0; j < y; ++j){
            cin >> dp[i][j];

            if (dp[i][j] == 'I'){
                vis[i][j] = 1;
            }
        }
    }

    for (int i = 0; i<x; ++i){
        for (int j = 0; j < y; ++j){
            if (dp[i][j] == '.' && vis[i][j] == 0){
                q.push({{i, j}, 1});
                vis[i][j] = 1;
                v.push_back(calc());
            }
        }
    }

    sort(v.begin(), v.end(), greater<int>());

    for (int x : v){
        if (x <= n){
            n -= x;
            ++ans;
        }else{
            break;
        }
    }
    if (ans != 1)
        cout << ans << " rooms, " << n << " square metre(s) left over";
    else
        cout << ans << " room, " << n << " square metre(s) left over";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
