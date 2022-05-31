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

//completed : i, d, n, q
//to do : f, s

vector <int> adj[51];
bool vis[51];
int x, y, cnt = 0;
queue <pair<int, int>> q;
char c;
void clean(){
	for (int i = 1; i<=50; ++i){
		vis[i] = 0;
	}
}
void solve(){
	
		adj[1].push_back(6);
		adj[2].push_back(6);
		adj[3].push_back(4);
		adj[3].push_back(5);
		adj[3].push_back(6);
        adj[3].push_back(15);
		adj[4].push_back(3);adj[4].push_back(5);adj[4].push_back(6);adj[5].push_back(3);
        adj[5].push_back(3);adj[5].push_back(4);adj[5].push_back(6);adj[6].push_back(1);adj[6].push_back(2);
        adj[6].push_back(3);adj[6].push_back(4);adj[6].push_back(5);adj[6].push_back(7);adj[7].push_back(6);
        adj[7].push_back(8);adj[8].push_back(7);adj[8].push_back(9);adj[9].push_back(8);adj[9].push_back(10);
        adj[9].push_back(12);adj[10].push_back(9);adj[10].push_back(11);adj[11].push_back(10);
        adj[11].push_back(12);adj[12].push_back(9);adj[12].push_back(11);adj[12].push_back(13);
        adj[13].push_back(12);adj[13].push_back(14);adj[13].push_back(15);adj[14].push_back(13);
        adj[15].push_back(3);adj[15].push_back(13);adj[16].push_back(17);adj[16].push_back(18);
        adj[17].push_back(16);adj[17].push_back(18);adj[18].push_back(16);adj[18].push_back(17);

	while (true){
		cin >> c;

		if (c == 'q')
			return;
		else if (c == 'i'){
			cin >> x >> y;
			if (count(adj[x].begin(), adj[x].end(), y) == 0){
				adj[x].push_back(y);
				adj[y].push_back(x);
			}
		}else if (c == 'n'){
			cin >> x;
			cout << adj[x].size() << '\n';
		}else if (c == 'd'){
			cin >> x >> y;
			for (int i = 0; i<adj[x].size(); ++i){
				if (adj[x][i] == y){
					adj[x].erase(adj[x].begin() + i);
				}
			}
			for (int i = 0; i<adj[y].size(); ++i){
				if (adj[y][i] == x){
					adj[y].erase(adj[y].begin() + i);
				}
			}
		}else if (c == 'f'){
			cin >> x;

			clean();
			q.push({x, 0});
			vis[x] = 1;
			cnt = 0;
			while (q.size()){
				int cur = q.front().first;
				int dis = q.front().second;

				q.pop();
				for (int n : adj[cur]){
					if (vis[n])
						continue;
					vis[n] = 1;
					if (dis + 1 == 2){
						++cnt;
					}
					q.push({n, dis + 1});
				}
			}
			cout << cnt << '\n';
		}else{
			cin >> x >> y;

			clean();
			q.push({x, 0});
			vis[x] = 1;
			bool f = 0;
			while (q.size()){
				int cur = q.front().first;
				int dis = q.front().second;

				q.pop();
				for (int n : adj[cur]){
					if (n == y && f == 0){
						cout << dis + 1 << '\n';
						f = 1;
					}else if (vis[n])
						continue;

					vis[n] = 1;
					q.push({n, dis + 1});
				}
			}
			if (f == 0)
				cout << "Not connected\n";
		}
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
