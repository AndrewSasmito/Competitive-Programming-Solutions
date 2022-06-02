#include <bits/stdc++.h>
using namespace std;

int r, c;
int dp[22][22];
char grid[22][22];
void solve(){
	cin >> r >> c;

	for (int i = 1; i <= r; ++i){
		for (int j = 1; j <= c; ++j){
			cin >> grid[i][j];
		}
	}

	queue <pair<int, int>> q;

	dp[1][1] = 1;
	q.push({1, 1});

	while (q.size()){
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		if (x == c && y == r){
			break;
		}
		
		if (grid[y][x] == '+' || grid[y][x] == '|'){
			//go up
			if (dp[y-1][x] == -1 && grid[y-1][x] != '*' && y - 1 > 0){
				dp[y-1][x] = dp[y][x] + 1;
				q.push({y-1, x});
			}
			//go down
			if (dp[y+1][x] == -1 && grid[y+1][x] != '*' && y + 1 <= r){
				dp[y+1][x] = dp[y][x] + 1;
				q.push({y+1, x});
			}
		}
		if (grid[y][x] == '+' || grid[y][x] == '-'){
			//go left
			if (dp[y][x-1] == -1 && grid[y][x - 1] != '*' && x - 1 > 0){
				dp[y][x - 1] = dp[y][x] + 1;
				q.push({y, x - 1});
			}
			//go right
			if (dp[y][x+1] == -1 && grid[y][x + 1] != '*' && x + 1 <= c){
				dp[y][x + 1] = dp[y][x] + 1;
				q.push({y, x + 1});
			}
		}
	}
	cout << dp[r][c] << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tes;
	cin >> tes;

	while (tes--){
		for (int i = 1; i<=20; ++i){
			for (int j = 1; j<=20; ++j){
				dp[i][j] = -1;
			}
		}
		solve();
	}
}
