/*
ID: asasmit1
TASK: numtri
LANG: C++
*/
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

//Redid this questions so many times, I forgot what each variable does.
int n, m, x, y, ans = 0, last = 0, temp = 0, vert, tot = 0;
unordered_map <int, int> chck, bad;
bool vis[1000001];
vector <int> adj[100001], tmp;
int dfs(int x){
    vis[x] = 1;
    int ret = 0;
    if (chck[x] == 1){
        last = x;
        ret = 1;
    }

    for (int y : adj[x]){
        if (vis[y] == 1 || bad[y] == 1){
            continue;
        }
        ret |= dfs(y);
    }

    if (ret == 0){
        bad[x] = 1;
    }
    return ret;
}

int dfs1(int x){
    vis[x] = 1;
    
    ++tot;
    int ret1 = 0, ret2 = 0;
    for (int y : adj[x]){
        if (vis[y] == 1 || bad[y] == 1){
            continue;
        }
        int cur = dfs1(y) + 1;
        
        if (cur >= ret1){
            ret2 = ret1;
            ret1 = cur;
        }else if (cur > ret2){
            ret2 = cur;
        }
    }
    ans = max(ans, ret1 + ret2);
    return ret1;
}

void clean(){
    for (int i = 0; i<=n; ++i){
        vis[i] = 0;
    }
}
void solve(){
    cin >> n >> m;

    for (int i = 0; i<m; ++i){
        cin >> x;
        chck[x] = 1;
        tmp.push_back(x);
    }

    for (int i = 0; i<n-1; ++i){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(tmp[0]), clean();
    dfs(tmp[1]), clean();
    dfs1(tmp[0]);
    cout << ans + ((tot - ans - 1) * 2) << '\n';
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
