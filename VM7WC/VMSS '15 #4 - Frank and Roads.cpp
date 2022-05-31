#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define forloop(i,a,b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
typedef pair<int, int> pii;
typedef vector<int> vi;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0) 

char _;

vector <int> store;
vector <pair<int, int>> adj[2001];
bool vis[2001];
int dis[2001];

int t, n, m, g, ans = 0;
void solve(){
	scan(t); scan(n); scan(m); scan(g);
	
	fill(dis, dis+2001, 999999);

	for (int i = 0; i<g; ++i){
		int a; scan(a);
		store.push_back(a);
	}

	for (int i = 0; i<m; ++i){
		int a, b, c;
		scan(a); scan(b); scan(c);

		adj[a].push_back({c, b});
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	q.push({0, 0}); dis[0] = 0;

	while (q.size()){
		int cur = q.top().second;
		int distance = q.top().first;
		q.pop();
		if (vis[cur]) continue;
		vis[cur] = 1;

		for (auto x : adj[cur]){
			int house = x.second;
			int distances = x.first;

			if (dis[house] > distances + distance){
				dis[house] = distances + distance;
				q.push({distances + distance, house});
			}
		}
	}

	for (int i = 0; i<g; ++i){
		if (dis[store[i]] <= t) ++ans;
	}

	cout<<ans<<'\n';
}
 
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int testcases = 1;
	//cin >> testcases;
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){
	    
	// Normal
	solve();
	
	//Google
	//cout<<"Case #"<<number_of_total_test_cases<<": "<<google_answer;
	}
}
