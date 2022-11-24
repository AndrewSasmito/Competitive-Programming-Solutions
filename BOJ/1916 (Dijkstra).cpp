#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z, dis[1001];
bool vis[1001];
vector <pair<int, int>> adj[1001];
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i<m; ++i){
        cin >> x >> y >> z;
        adj[x].push_back(make_pair(z, y));
    }
    for (int i = 1; i<=n; ++i){
        dis[i] = 999999999;
    }
    cin >> x >> y;
    dis[x] = 0, q.push({0, x});

    while (q.size()){
        int dists = q.top().first, cur = q.top().second;
        q.pop();

        if (vis[cur] == 1)
            continue;
        vis[cur] = 1;
        for (auto x : adj[cur]){
            if (vis[x.second] == 1)
                continue;
            int h = x.second, dist = x.first;

            if (dis[h] > dist + dists){
                dis[h] = dist + dists;
                q.push({dist + dists, h});
            }
        }
    }
    cout << dis[y] << '\n';
}
