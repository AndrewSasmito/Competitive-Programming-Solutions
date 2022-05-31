#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, c, x;
int dis[10001];
vector <int> adj[10001];
vector <int> check;
queue <int> q;
void solve(){
	cin >> n;

	for (int i = 1; i<=n; ++i){
		cin >> c;
		
		if (c == 0){
			check.push_back(i);
			continue;
		}

		for (int j = 0; j<c; ++j){
			cin >> x;
			adj[i].push_back(x);
		}
	}

	int ans = 200000;

	q.push(1);
	dis[1] = 1;
	while (q.size()){
		int cur = q.front();
		q.pop();
	
		for (int x : adj[cur]){
			if (dis[x] > 0)
				continue;
			
			dis[x] = dis[cur] + 1;
			q.push(x);
		}
	}

	bool f = 0;
	for (int i = 1; i<=n; ++i){
		if (dis[i] == 0){
			f = 1;
			break;
		}
	}
	cout << (f == 0 ? 'Y' : 'N') << '\n';

	for (int x : check){
		if (dis[x] == 0)
			continue;
		ans = min(ans, dis[x]);
	}
	cout << ans << '\n';
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
