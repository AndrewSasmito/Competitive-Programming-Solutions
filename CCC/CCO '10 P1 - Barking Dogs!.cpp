#include <bits/stdc++.h>
using namespace std;

int n, t, x, y, ans[1001], z;
vector <int> v, adj[1001];
queue <int> qu;
bool vis[1001];
int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    priority_queue <pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> q;
    cin >> n;
    v.push_back(0);
    for (int i = 0; i<n; ++i){
        cin >> x;
        v.push_back(x);
    }
    cin >> z;
    for (int i = 0; i<z; ++i){
        cin >> x >> y;

        adj[x].push_back(y);
    }
    cin >> t;
    ans[1] = 1;
    vis[1] = 1;
    for (int x : adj[1]){
        q.push({v[x], x});
        vis[x] = 1;
    }
    vis[1] = 0;

    for (int i = 1; i<=t; ++i){
        while (qu.size()){
            vis[qu.front()] = 0;
            qu.pop();
        }
        while (q.top().first <= i){
            int cur = q.top().second;
            q.pop();
            ++ans[cur];
            for (int x : adj[cur]){
                if (vis[x] == 0){
                    q.push({v[x] + i, x});
                    vis[x] = 1;
                }
            }
            qu.push(cur);
        }
    }

    for (int i = 1; i<=n; ++i){
        cout << ans[i] << '\n';
    }
}
