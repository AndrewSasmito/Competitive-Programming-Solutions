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

int n, t;
vector <pair<int, int>> adj[5001];
vector <pair <int, int>> store;
bool vis[5001];
int dis[5001], ans = 999999;
void solve(){
	scan(n); scan(t);

	for (int i = 0; i<t; ++i){
		int x, y, c;
		scan(x); scan(y); scan(c);

		adj[x].push_back({c, y});
		adj[y].push_back({c, x});
	}
	int shops;
	scan(shops);

	for (int i = 0; i<shops; ++i){
		int x, y;
		scan(x); scan(y);
		store.push_back({x, y});
	}
	int d;
	scan(d);

	fill(dis, dis+5001, 999999);
	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	
	q.push({0, d}); dis[d] = 0;

	while (q.size()){
		int cur = q.top().second;
		int distance = q.top().first;
		q.pop();
		if (vis[cur]) continue;
		vis[cur] = 1;
			for (auto x : adj[cur]){
			int firsts = x.second;
			int seconds = x.first;
				if (dis[firsts]> seconds + distance){
				q.push({seconds + distance, firsts});
				dis[firsts] = seconds + distance;
			}
		}
	}
	
	for (int i = 0; i<shops; ++i){
		ans = min(ans, dis[store[i].first] + store[i].second);
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
