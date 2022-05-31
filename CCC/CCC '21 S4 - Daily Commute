#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
int n, w, d, x, y;
int dis[200001];
int vis[200001];
unordered_map <int, int> m;
vector <int> adj[200001];
multiset <int> ms;
queue <pair<int, int>> q;
void solve(){
	cin >> n >> w >> d;

	for (int i = 1; i<=w; ++i){
		cin >> x >> y;
		adj[y].push_back(x);
	}

	for (int i = 1; i<=n; ++i){
		cin >> y;
		m[i] = y;
	}

	for (int i = 1; i<=200000; ++i){
		dis[i] = 4000000;
	}
	q.push({n, 0});
	dis[n] = 0;
	while (q.size()){
		int cur = q.front().first;
		int dist = q.front().second;
		q.pop();

		for (int r : adj[cur]){
			if (dis[r] == 4000000){
				dis[r] = dist + 1;
				q.push({r, dist + 1});
			}
		}
	}

	for (int j = 1; j<=n; ++j){
		ms.insert(dis[m[j]] + j);
	}

	for (int i = 0; i<d; ++i){
		cin >> x >> y;
		int h1 = m[x];
		int h2 = m[y];

		ms.erase(ms.find(dis[m[x]] + x));
		ms.erase(ms.find(dis[m[y]] + y));
		m[x] = h2;
		m[y] = h1;
		ms.insert(dis[m[x]] + x);
		ms.insert(dis[m[y]] + y);


		cout << (*ms.begin()) - 1 << '\n';
	}
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	
    int testcases = 1;
   	//cin >> testcases;
    for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
    

    //Google
    //cout<<"Case #"<<number_of_total_test_cases<<": ";:
    // Normal
		solve();
    }

}
