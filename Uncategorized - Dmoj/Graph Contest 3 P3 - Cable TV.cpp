#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedtime ((double)(clock()-__init_time__)/clocks_per_sec)<<" seconds"
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
//custom hash for hash map
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t fixed_random = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + fixed_random);
    }

	/*
	 	* How To Use:
	 	*
	 	* unordered_map<long long, int, custom_hash> safe_map;
	 	* gp_hash_table<long long, int, custom_hash> safe_hash_table;
	 	*
	 */
};



void usaco(){

	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);

	/*
		 * How To Use:
		 *
		 * Call usaco() to take input and output
		 * to & from a textfile
		 *
		 * freopen("File Name", "r" or "w", stdin or stdout);
		 *
		 * r && stdin == read
		 *
		 * w && stdout == print
		 *
	 */
}

int n, m, a, b, c, d, par[101], cost = 0, bad = 0;
bool vis[101];
vector <pair<int, pair<int, int>>> tmp;
priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

int parent(int x){
	return x == par[x] ? x : par[x] = parent(par[x]);
}

void calc(int z){
	while (q.size()){
		int cst = q.top().first, f = q.top().second.first, s = q.top().second.second;
		q.pop();
		if (parent(f) == parent(s)){
			continue;
		}

		par[parent(f)] = parent(s);
		vis[f] = 1, vis[s] = 1;
		bad += z;
		cost += cst;
	}
}

bool chck(){
	for (int i = 1; i<=n; ++i){
		if (vis[i] == 0){
			return 0;
		}
	}
	return 1;
}
void solve(){
	cin >> n >> m;

	for (int i = 1; i<=n; ++i){
		par[i] = i;
	}
	
	for (int i = 0; i<m; ++i){
		cin >> a >> b >> c >> d;

		if (d == 0){
			q.push(make_pair(c, make_pair(a, b)));
		}else{
			tmp.push_back(make_pair(c, make_pair(a, b)));
		}
	}

	calc(0);

	if (chck()){
		cout << bad << ' ' << cost << '\n';
		return;
	}

	for (auto x : tmp)
		q.push(x);

	calc(1);

	cout << bad << ' ' << cost << '\n';
}	

//do not submit if usaco(); is open


/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

int main(){
	//Speed up
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
