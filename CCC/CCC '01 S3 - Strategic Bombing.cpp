#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

string s, con = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vector <int> adj[30];
bool vis[27];
queue <int> q;
vector <pair<int, int>> v;

bool check(int x, int y){
	for (int i = 1; i < 26; ++i){ vis[i] = 0; }

	q.push(0);
	while (q.size()){
		int cur = q.front();
		q.pop();

		for (int z : adj[cur]){
			if (vis[z])
				continue;
			if ((z == x && cur == y) || (z == y && cur == x))
				continue;

			vis[z] = 1;
			q.push(z);
		}
	}

	if (vis[1]){
		return 0;
	}
	else{
		return 1;
	}
}


void solve(){
	vis[0] = 1;
	while (true){
		cin >> s;

		if (s == "**")
			break;
		
		adj[s[0] - 'A'].push_back(s[1] - 'A');
		adj[s[1] - 'A'].push_back(s[0] - 'A');
	}

	for (int i = 0; i < 26; ++i){
		for (int j = i + 1; j < 26; ++j){
			if (check(i, j)){
				v.push_back({i, j});
			}
		}
	}

	for (int i = 0; i<v.size(); ++i){
		cout << con[v[i].first] << con[v[i].second] << '\n';
	}
	cout << "There are " << v.size() << " disconnecting roads.\n";
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

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

	//cout << elapsedTime << '\n';
}
