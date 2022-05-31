#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, m;
string x;
vector <string> adj;
int dis[101][101];
bool vis[101][101];
bool imp = 0;
queue <pair<int, int>> q;

void con(int x, int y, int distance){
	bool visit[101][101];
	for (int i = 0; i<=100; ++i){
		for (int j = 0; j<=100; ++j){
			visit[i][j] = 0;
		}
	}
	//conveyer code
	//Check for infinite loop
	//if the conveyer leads to a wall or a visited place dont push onto the q
	//x and y is the conveyer position
	
	while(true){
		if (visit[x][y] == 1){
			return;
		}else if (adj[x][y] == 'D'){
			visit[x][y] = 1;
			++x;
		}else if (adj[x][y] == 'U'){
			visit[x][y] = 1;
			--x;
		}else if (adj[x][y] == 'R'){
			visit[x][y] = 1;
			++y;
		}else if (adj[x][y] == 'L'){
			visit[x][y] = 1;
			--y;
		}else if (adj[x][y] == '.' && vis[x][y] == 0){
			q.push({x, y});
			dis[x][y] = distance;
			vis[x][y] = 1;
			return;

		}else
			return;
	}
}
void solve(){

	// <m && <n
	// This is the graph starts at 0
	// Check the distance of .
	


	cin>>n>>m;
	for (int i = 0; i<n; ++i){
		cin>>x;
		adj.push_back(x);
	}



	int startx, starty, curx, cury, curdis;

	for (int i = 0; i<n; ++i){
		for (int j = 0; j<m; ++j){
			if (adj[i][j] == 'W'){
				vis[i][j] = 1;
			}else if (adj[i][j] == 'C'){
				q.push({i, j});
				vis[i][j] = 1;
			}else if (adj[i][j] == 'S'){
				startx = i;
				starty = j;
				dis[i][j] = 0;
				vis[i][j] = 1;
			}
		}
	}
	//check the cameras
	
	while (q.size()){
		curx = q.front().first;
		cury = q.front().second;
		q.pop();
		int i = 1;
		//going down
		while (true){
			if (adj[i + curx][cury] == '.')
				vis[i + curx][cury] = 1;
			else if (adj[i + curx][cury] == 'S'){
				imp = 1;
				break;
			}
			else if (adj[i + curx][cury] == 'W')
				break;

			++i;
		}
		//going up
		i = -1;
		while (true){
			if (adj[i + curx][cury] == '.')
				vis[i + curx][cury] = 1;
			else if (adj[i + curx][cury] == 'W')
				break;
			else if (adj[i + curx][cury] == 'S'){
				imp = 1;
				break;
			}
			--i;

		}
		// going right
		i = 1;
		while (true){
			if (adj[curx][cury + i] == '.')
				vis[curx][cury + i] = 1;
			else if (adj[curx][cury + i] == 'W')
				break;
			else if (adj[curx][cury + i] == 'S'){
				imp = 1;
				break;
			}
			++i;
		}
		//going left
		i = -1;
		while (true){
			if (adj[curx][i + cury] == '.')
				vis[curx][i + cury] = 1;
			else if (adj[curx][i + cury] == 'W')
				break;
			else if (adj[curx][cury + i] == 'S'){
				imp = 1;
				break;
			}
			--i;
		}
	}

	//pushing s onto the q
	
	if (imp == 0){
		//be careful if a conveyer goes straight into a wall
		q.push({startx, starty});
	
		while(q.size()){
			curx = q.front().first;
			cury = q.front().second;
			curdis = dis[curx][cury];
			q.pop();

			if (vis[1 + curx][cury] == 0){
				//up
				if (adj[1 + curx][cury] == '.'){
					vis[1 + curx][cury] = 1;
					dis[1 + curx][cury] = 1 + curdis;
					q.push({1 + curx, cury});
				}else{
					con(1+curx, cury, 1 + curdis);
				}
			}if (vis[-1 + curx][cury] == 0){
				//down
				if (adj[-1 + curx][cury] == '.'){
					vis[-1 + curx][cury] = 1;
					dis[-1 + curx][cury] = 1 + curdis;
					q.push({-1 + curx, cury});
				}else{
					con(-1+curx, cury, 1 + curdis);
				}
			} if (vis[curx][cury + 1] == 0){
				//right
				if (adj[curx][cury + 1] == '.'){
					vis[curx][cury + 1] = 1;
					dis[curx][cury + 1] = 1 + curdis;
					q.push({curx, 1 + cury});
				}else{
					con(curx, 1 + cury, 1 + curdis);
				}
			} if (vis[curx][-1 + cury] == 0){
				//left
				if (adj[curx][-1 + cury] == '.'){
					vis[curx][-1 + cury] = 1;
					dis[curx][-1 + cury] = 1 + curdis;
					q.push({curx, -1 + cury});
				}else{
					con(curx, -1 + cury, 1 + curdis);
				}
			}
	
		}
	}


	//the output (This could never be wrong)
	for (int i = 0; i<n; ++i){
		for (int j = 0; j<m; ++j){
			if (adj[i][j] == '.'){
				if (dis[i][j] == 0){
					cout<<-1<<'\n';
				}else
					cout<<dis[i][j]<<'\n';
			}
		}
	}
}

 
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int testcases = 1;
	//cin >> testcases;
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
	

	// Normal
	solve();
	//Google
	//cout<<"Case #"<<number_of_total_test_cases<<": "<<google_answer;
	}
}
