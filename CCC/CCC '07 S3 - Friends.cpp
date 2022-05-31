#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, x, y;
vector <int> adj[10000];
queue <int> q;
int dis[10000];
void solve(){
	cin >> n;

	for (int i = 0; i<n; ++i){
		cin >> x >> y;
		adj[x].push_back(y);
	}
	
	while (true){
		cin >> x >> y;

		if (x == 0 && y == 0)
			break;

		for (int i = 1; i<=9999; ++i){
			dis[i] = 0;
		}

		q.push(x);
		
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

		if (dis[y] > 0 || y == x){
			cout << "Yes " << dis[y] - 1 << '\n';
		}else{
			cout << "No\n";
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
