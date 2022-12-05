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
int n, x, y, grid[1001][1001], cnt = 0, vis[1001][1001];
void solve(){
	cin >> n;

	for (int i = 1; i<=n; ++i){
		cin >> x >> y;
        //vis[x][y] == 2 means that it was claimed
		if (x != 0){
			++grid[y][x - 1];
			if (grid[y][x - 1] == 3 && vis[y][x - 1] == 1){
				++cnt;
				vis[y][x - 1] = 2;
			}else if (grid[y][x - 1] == 4 && vis[y][x - 1] == 2){
				--cnt;
				vis[y][x - 1] = 1;
			}
		}if (x != 1000){
			++grid[y][x + 1];
			if (grid[y][x + 1] == 3 && vis[y][x + 1] == 1){
				++cnt;
				vis[y][x + 1] = 2;
			}else if (grid[y][x + 1] == 4 && vis[y][x + 1] == 2){
				--cnt;
				vis[y][x + 1] = 1;
			}
		}if (y != 0){
			++grid[y - 1][x];
			if (grid[y - 1][x] == 3 && vis[y - 1][x] == 1){
				++cnt;
				vis[y - 1][x] = 2;
			}else if (grid[y - 1][x] == 4 && vis[y - 1][x] == 2){
				--cnt;
				vis[y - 1][x] = 1;
			}
		}if (y != 1000){
			++grid[y + 1][x];
			if (grid[y + 1][x] == 3 && vis[y + 1][x] == 1){
				++cnt;
				vis[y + 1][x] = 2;
			}else if (grid[y + 1][x] == 4 && vis[y + 1][x] == 2){
				--cnt;
				vis[y + 1][x] = 1;
			}
		}
		
		cnt += (grid[y][x] == 3);
        vis[y][x] = 1;
		cout << cnt << '\n';
	}
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
