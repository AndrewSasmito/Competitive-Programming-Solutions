#include <bits/stdc++.h>
using namespace std;

const int MX = 10001;
int n, e, par[MX], ans = 0, mn = 0, x;
vector <pair<int, pair<int, int>>> adj[MX];
vector <pair<int, pair<int, int>>> g;
priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
int parent(int x){
	return x == par[x] ? par[x] : par[x] = parent(par[x]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i<n; ++i){
		cin >> e;
		vector <int> v;
		for (int j = 0; j<e; ++j){
			cin >> x;
			v.push_back(x);
		}
		for (int j = 0; j<e - 1; ++j){
			cin >> x;
			adj[v[j]].push_back(make_pair(x, make_pair(v[j + 1], i + 1)));
			adj[v[j + 1]].push_back(make_pair(x, make_pair(v[j], i + 1)));
		}
		cin >> x;
		adj[v[e - 1]].push_back(make_pair(x, make_pair(v[0], i + 1)));
		adj[v[0]].push_back(make_pair(x, make_pair(v[e - 1], i + 1)));
	}

	for (int i = 1; i<=n; ++i){
		par[i] = i;
	}

	for (int i = 1; i<=1000; ++i){
		for (int j = 0; j<adj[i].size(); ++j){
			x = 0;
			for (int k = 0; k<adj[i].size(); ++k){
				if (j == k){
					continue;
				}else if (adj[i][j].second.first == adj[i][k].second.first){
					x = adj[i][k].second.second;
				}
			}
			
			if (x == 0){
				g.push_back({adj[i][j].first, {adj[i][j].second.second, x}});
			}else{
				g.push_back({adj[i][j].first, {adj[i][j].second.second, x}});
				q.push({adj[i][j].first, {adj[i][j].second.second, x}});
			}
		}
	}


	while (q.size()){
		int cost = q.top().first, par1 = q.top().second.first, par2 = q.top().second.second;
		q.pop();
		if (parent(par1) != parent(par2)){
			ans += cost;
			if (parent(par1) < parent(par2)){
				par[parent(par2)] = parent(par1);
			}else{
				par[parent(par1)] = parent(par2);
			}
		}
		set <int> s;
		for (int i = 1; i<=n; ++i){
			s.insert(parent(i));
		}

		if (s.size() <= 1){
			break;
		}
	}

	for (int i = 1; i<=n; ++i){
		par[i] = i;
	}
	for (int j = 0; j<g.size(); ++j){
		q.push({g[j].first, {g[j].second.first, g[j].second.second}});
	}

	while (q.size()){
		int cost = q.top().first, par1 = q.top().second.first, par2 = q.top().second.second;
		q.pop();
		if (parent(par1) != parent(par2)){
			mn += cost;
			if (parent(par1) < parent(par2)){
				par[parent(par2)] = parent(par1);
			}else{
				par[parent(par1)] = parent(par2);
			}
		}
		set <int> s;
		for (int i = 1; i<=n; ++i){
			s.insert(parent(i));
		}

		if (s.size() <= 1){
			break;
		}
	}

	cout << min(ans, mn) << '\n';
}
