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
int n;
bool vis[501][501];
int dis[501][501];
queue <pair<int, int>> q;
int a, b, x, y;
bool check(int x, int y){
	if (x < 1)
		return 0;
	else if (8 < x)
		return 0;
	else if (y < 1)
		return 0;
	else if (8 < x)
		return 0;

	return 1;
}

void solve(){
	cin >> a >> b >> x >> y;

	vis[a][b] = 1;
	q.push({a, b});

	while (q.size()){
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		
		//cout << curx << ' ' << cury << '\n';
		if (vis[x][y]){
			cout << dis[x][y] << '\n';
			return;
		}
		if (check(curx - 2, cury + 1))
			if (vis[curx - 2][cury + 1] == 0){
				dis[curx-2][cury+1] = dis[curx][cury] + 1;
				vis[curx-2][cury+1] = 1;
				q.push({curx-2, cury+1});
			}

		if (check(curx - 2, cury - 1))
			if (vis[curx-2][cury-1] == 0){
				dis[curx-2][cury-1] = dis[curx][cury] + 1;
				vis[curx-2][cury-1] = 1;
				q.push({curx - 2, cury - 1});
			}


		if (check(curx - 1, cury + 2))
			if (vis[curx - 1][cury + 2] == 0){
				dis[curx - 1][cury + 2] = dis[curx][cury] + 1;
				vis[curx - 1][cury + 2] = 1;
				q.push({curx-1, cury+2});
			}


		if (check(curx - 1, cury - 2))
			if (vis[curx - 1][cury - 2] == 0){
				dis[curx - 1][cury - 2] = dis[curx][cury] + 1;
				vis[curx - 1][cury - 2] = 1;
				q.push({curx-1, cury-2});
			}




		if (check(curx + 2, cury - 1))
			if (vis[curx + 2][cury - 1] == 0){
				dis[curx + 2][cury - 1] = dis[curx][cury] + 1;
				vis[curx + 2][cury - 1] = 1;
				q.push({curx + 2, cury - 1});
			}

		if (check(curx + 2, cury + 1))
			if (vis[curx + 2][cury + 1] == 0){
				dis[curx + 2][cury + 1] = dis[curx][cury] + 1;
				vis[curx + 2][cury + 1] = 1;
				q.push({curx + 2, cury + 1});
			}


		if (check(curx + 1, cury + 2))
			if (vis[curx + 1][cury + 2] == 0){
				dis[curx + 1][cury + 2] = dis[curx][cury] + 1;
				vis[curx + 1][cury + 2] = 1;
				q.push({curx + 1, cury + 2});
			}


		if (check(curx + 1, cury - 2))
			if (vis[curx + 1][cury - 2] == 0){
				dis[curx + 1][cury - 2] = dis[curx][cury] + 1;
				vis[curx + 1][cury - 2] = 1;
				q.push({curx + 1, cury - 2});
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
