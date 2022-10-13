#include <bits/stdc++.h>
using namespace std;

int n, m, start, x, y;
bool vis[10001];
vector <int> adj[10001];
queue <int> q;

void dfs(int x){

    if (vis[x] == 1){
        return;
    }

    cout << x << ' ';
    vis[x] = 1;

    for (int z : adj[x]){
        if (vis[z] == 1){
            continue;
        }
        dfs(z);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> start;

    for (int i = 0; i<m; ++i){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 0; i<=n; ++i){
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(start);
    cout << '\n';

    for (int i = 0; i<=n; ++i){
        vis[i] = 0;
    }
    q.push(start);
    cout << start << ' ';

    vis[start] = 1;

    while (q.size()){
        int cur = q.front();
        q.pop();

        for (int x : adj[cur]){
            if (vis[x] == 1){
                continue;
            }

            cout << x << ' ';
            vis[x] = 1;
            q.push(x);
        }
    }
    cout << '\n';
}
