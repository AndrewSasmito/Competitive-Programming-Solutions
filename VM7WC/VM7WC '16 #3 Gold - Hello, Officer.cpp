#include <bits/stdc++.h>
using namespace std;

vector <pair<int, int>> adj[5001];
bool vis[5001];
int dis[5001];

void solve(){
    int n, m, b, qs;
	cin>>n>>m>>b>>qs;

	memset(dis, 9999, sizeof(dis));

	for (int i = 0; i<m; ++i){
		int x, y, z;
		cin>>x>>y>>z;

		adj[x].push_back({z, y});
		adj[y].push_back({z, x});
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	q.push({0, b}); dis[b] = 0;

	while (q.size()){
		int cur = q.top().second;
		int distance = q.top().first;
		q.pop();
		if (vis[cur]) continue;
		vis[cur] = 1;

		for (auto x: adj[cur]){
			int fir = x.second;
			int sec = x.first;

			if (dis[fir]>distance+sec){
				q.push({sec + distance, fir});
				dis[fir] = sec + distance;
			}
		}
	}

	for (int i = 0; i<qs; ++i){
		int y; cin>>y;
		if (vis[y] == 0) cout<<-1<<'\n';
		else cout<<dis[y]<<'\n';
	}
}







int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int cases = 1; //cin>>cases;

	while (cases--) solve();
}
