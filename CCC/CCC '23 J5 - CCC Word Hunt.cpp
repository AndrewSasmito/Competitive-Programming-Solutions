#include <bits/stdc++.h>
using namespace std;

int ans = 0, n, m;
char dp[101][101];
string s;

void dfs(int x, int y, string st, bool f, bool ss, int ty){

	if (st == s){
		//cout << x << ' ' << y << ' ' << s << ' ' << f << ' ' << ss << ' ' << ty << ' ' << dp[x][y] << '\n';
		++ans;
		return;
	}
	st += 'z';
	st.back() = s[st.size() - 1];

	if (f == 1){
		if (x != 0 && dp[x - 1][y] == s[st.size() - 1]){
			if (ty == 2){

			}else if (ty != 1){
				if (ss == 0)
					dfs(x - 1, y, st, f, 1, 1);
			}else{
				dfs(x - 1, y, st, f, ss, ty);
			}
		}if (x != n - 1 && dp[x + 1][y] == s[st.size() - 1]){
			if (ty == 1){
				
			}else if (ty != 2){
				if (ss == 0)
					dfs(x + 1, y, st, f, 1, 2);
			}else{
				dfs(x + 1, y, st, f, ss, ty);
			}
		}if (y != 0 && dp[x][y - 1] == s[st.size() - 1]){
			if (ty == 4){

			}else if (ty != 3){
				if (ss == 0)
					dfs(x, y - 1, st, f, 1, 3);
			}else{
				dfs(x, y - 1, st, f, ss, ty);
			}
		}if (y != m - 1 && dp[x][y + 1] == s[st.size() - 1]){
			if (ty == 3){

			}else if (ty != 4){
				if (ss == 0)
					dfs(x, y + 1, st, f, 1, 4);
			}else{
				dfs(x, y + 1, st, f, ss, ty);
			}
		}
	}else{
		if (x != 0 && y != 0 && dp[x - 1][y - 1] == s[st.size() - 1]){
			if (ty == 4){

			}else if (ty != 1){
				if (ss == 0)
					dfs(x - 1, y - 1, st, f, 1, 1);
			}else{
				dfs(x - 1, y - 1, st, f, ss, ty);
			}
		}if (x != 0 && y != m - 1 && dp[x - 1][y + 1] == s[st.size() - 1]){
			if (ty == 3){

			}else if (ty != 2){
				if (ss == 0)
					dfs(x - 1, y + 1, st, f, 1, 2);
			}else{
				dfs(x - 1, y + 1, st, f, ss, ty);
			}
		}if (x != n - 1 && y != 0 && dp[x + 1][y - 1] == s[st.size() - 1]){
			if (ty == 2){

			}else if (ty != 3){
				if (ss == 0)
					dfs(x + 1, y - 1, st, f, 1, 3);
			}else{
				dfs(x + 1, y - 1, st, f, ss, ty);
			}
		}if (x != n - 1 && y != m - 1 && dp[x + 1][y + 1] == s[st.size() - 1]){
			if (ty == 1){

			}else if (ty != 4){
				if (ss == 0)
					dfs(x + 1, y + 1, st, f, 1, 4);
			}else{
				dfs(x + 1, y + 1, st, f, ss, ty);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> n >> m;
	for (int i = 0; i<n; ++i){
		for (int j = 0; j<m; ++j){
			cin >> dp[i][j];
		}
	}

	for (int i = 0; i<n; ++i){
		for (int j = 0; j<m; ++j){
		    if (dp[i][j] != s[0]){
		        continue;
		    }
			string t = "";
			t += dp[i][j];
			t += s[1];
			if (i != 0 && dp[i - 1][j] == s[1]){
				dfs(i - 1, j, t, 1, 0, 1);
			}if (i != n - 1 && dp[i + 1][j] == s[1]){
				dfs(i + 1, j, t, 1, 0, 2);
			}if (j != 0 && dp[i][j - 1] == s[1]){
				dfs(i, j - 1, t, 1, 0, 3);
			}if (j != m - 1 && dp[i][j + 1] == s[1]){
				dfs(i, j + 1, t, 1, 0, 4);
			}


			if (i != 0 && j != 0 && dp[i - 1][j - 1] == s[1]){
				dfs(i - 1, j - 1, t, 0, 0, 1);
			}if (i != 0 && j != m - 1 && dp[i - 1][j + 1] == s[1]){
				dfs(i - 1, j + 1, t, 0, 0, 2);
			}if (i != n - 1 && j != 0 && dp[i + 1][j - 1] == s[1]){
				dfs(i + 1, j - 1, t, 0, 0, 3);
			}if (i != n - 1 && j != m - 1 && dp[i + 1][j + 1] == s[1]){
				dfs(i + 1, j + 1, t, 0, 0, 4);
			}
			
		}
	}
	cout << ans << '\n';
}
