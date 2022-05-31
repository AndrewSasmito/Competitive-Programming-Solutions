#include <bits/stdc++.h>
using namespace std;
 
#define long long ll
#define forloop(i,a,b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
 
 
const int MN = 2005;
vector<int> adj[MN];
bool vis[MN];
void solve(){
	int n, m, a, b;
	cin>>n>>m>>a>>b;

	for (int i = 0,x, y; i<m; ++i){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);

	}
	

	queue <int> q; q.push(a);

	vis[a] = 1;

	while (!q.empty()){
		int current = q.front();
		q.pop();

		for (int neigh : adj[current]){
			if (vis[neigh]) continue;

			q.push(neigh);
			vis[neigh] = 1;
		}

	}
	
	if (vis[b]) cout<<"GO SHAHIR!";
	else cout<<"NO SHAHIR!";
}
 
 

 
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
