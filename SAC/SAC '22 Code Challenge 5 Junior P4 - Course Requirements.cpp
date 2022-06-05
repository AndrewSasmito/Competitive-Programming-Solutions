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
const int MM = 2e5 + 1;
vector <int> adj[MM];
queue <int> q;
int vis[MM], n, x, c;
void solve(){
	cin >> n;

	for (int i = 1; i<=n; ++i){
		cin >> c;

		if (c == 0){
			q.push(i);
			cout << i << ' ';
		}else{
			vis[i] = c;
			for (int j = 0; j<c; ++j){
				cin >> x;
				adj[x].push_back(i);
			}
		}
	}

	while (q.size()){
		int cur = q.front();
		q.pop();

		for (int x : adj[cur]){
			--vis[x];

			if (vis[x] == 0){
				q.push(x);
				cout << x << ' ';
			}
		}
	}
	cout << '\n';
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
