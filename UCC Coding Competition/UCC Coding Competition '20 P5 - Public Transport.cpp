#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int dis[1001], l, start, ender, n, x, y;
queue <int> q;
vector <int> adj[1001];
void solve(){
	cin >> l >> start >> ender >> n;

	for (int i = 0; i<n; ++i){
		cin >> x >> y;
		adj[x].push_back(y);
	}

	q.push(start);
	while (q.size()){
		int cur = q.front();
		q.pop();

		for (int h : adj[cur]){
			if (h == ender){
				cout << dis[cur] + 1 << '\n';
				return;
			}
			if (dis[h] > 0)
				continue;
			
			dis[h] = dis[cur] + 1;
			q.push(h);
		}
	}
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int testcases = 1;
    //cin >> testcases;
    for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
    

    //Google
    //cout<<"Case #"<<number_of_total_test_cases<<": ";
    // Normal
    solve();
    }

}
