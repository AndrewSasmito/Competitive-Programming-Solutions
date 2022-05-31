#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n, m, x, y, p, q;
queue <int> qs;
vector <int> adj[100001];
bool vis[100001];
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i<m; ++i){
		scanf("%d%d", &x, &y);
		adj[y].push_back(x);
	}

	scanf("%d%d", &p, &q);

	qs.push(p);

	while (qs.size()){
		int cur = qs.front();
		qs.pop();

		for (int x : adj[cur]){
			if (vis[x])
				continue;

			vis[x] = 1;
			qs.push(x);
		}
	}
	if (vis[q]){
		printf("no\n");
		return 0;
	}

	qs.push(q);
	while (qs.size()){
		int cur = qs.front();
		qs.pop();

		for (int x : adj[cur]){
			if (x == p){
				printf("yes\n");
				return 0;
			}
			if (vis[x])
				continue;

			vis[x] = q;

			qs.push(x);
		}
	}
	printf("unknown\n");
}
