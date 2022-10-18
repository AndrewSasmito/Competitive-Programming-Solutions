#include <bits/stdc++.h>
using namespace std;

string s;
int n, m, dis[2][1002][1002];
bool grid[1002][1002];
queue <pair<bool, pair<int, int>>> q;
void bfs(){
    for (int i = 1; i<=n; ++i){
        for (int j = 1; j<=m; ++j){
            dis[0][i][j] = -1;
            dis[1][i][j] = -1;
        }
    }

    dis[0][1][1] = 1;
    dis[1][1][1] = 1;

    q.push({1, {1, 1}});

    while (q.size()){
        auto cur = q.front();
        q.pop();

            //Down
            if (grid[cur.second.first + 1][cur.second.second] == 1 && dis[1][cur.second.first + 1][cur.second.second] == -1){
                if (cur.first == 1){
                    dis[0][cur.second.first + 1][cur.second.second] = dis[cur.first][cur.second.first][cur.second.second] + 1;
                    q.push({0, {cur.second.first + 1, cur.second.second}});
                }
            }else if (grid[cur.second.first + 1][cur.second.second] == 0 && dis[cur.first][cur.second.first + 1][cur.second.second] == -1){
                dis[cur.first][cur.second.first + 1][cur.second.second] = dis[cur.first][cur.second.first][cur.second.second] + 1;
                q.push({cur.first, {cur.second.first + 1, cur.second.second}});
            }
            //Up
            if (grid[cur.second.first - 1][cur.second.second] == 1 && dis[1][cur.second.first - 1][cur.second.second] == -1){
                if (cur.first == 1){
                    dis[0][cur.second.first - 1][cur.second.second] = dis[cur.first][cur.second.first][cur.second.second] + 1;
                    q.push({0, {cur.second.first - 1, cur.second.second}});
                }
            }else if (grid[cur.second.first - 1][cur.second.second] == 0 && dis[cur.first][cur.second.first - 1][cur.second.second] == -1){
                dis[cur.first][cur.second.first - 1][cur.second.second] = dis[cur.first][cur.second.first][cur.second.second] + 1;
                q.push({cur.first, {cur.second.first - 1, cur.second.second}});
            }
        //Right

            if (grid[cur.second.first][cur.second.second + 1] == 1 && dis[1][cur.second.first][cur.second.second + 1] == -1){
                if (cur.first == 1){
                    dis[0][cur.second.first][cur.second.second + 1] = dis[cur.first][cur.second.first][cur.second.second] + 1;
                    q.push({0, {cur.second.first, cur.second.second + 1}});
                }
            }else if (grid[cur.second.first][cur.second.second + 1] == 0 && dis[cur.first][cur.second.first][cur.second.second + 1] == -1){
                dis[cur.first][cur.second.first][cur.second.second + 1] = dis[cur.first][cur.second.first][cur.second.second] + 1;
                q.push({cur.first, {cur.second.first, cur.second.second + 1}});
            }


        //Left

            if (grid[cur.second.first][cur.second.second - 1] == 1 && dis[1][cur.second.first][cur.second.second - 1] == -1){
                if (cur.first == 1){
                    dis[0][cur.second.first][cur.second.second - 1] = dis[cur.first][cur.second.first][cur.second.second] + 1;
                    q.push({0, {cur.second.first, cur.second.second - 1}});
                }
            }else if (grid[cur.second.first][cur.second.second - 1] == 0 && dis[cur.first][cur.second.first][cur.second.second - 1] == -1){
                dis[cur.first][cur.second.first][cur.second.second - 1] = dis[cur.first][cur.second.first][cur.second.second] + 1;
                q.push({cur.first, {cur.second.first, cur.second.second - 1}});
            }

    }
}

int main(){
    cin >> n >> m;

    for (int i = 0; i<=n + 1; ++i){
        if (1 <= i && i <= n){
            cin >> s;
        }
        for (int j = 0; j<=m + 1; ++j){
            if (i == 0 || j == 0){
                grid[i][j] = 1;
            }else if (i == n + 1 || j == m + 1){
                grid[i][j] = 1;
            }else{
                grid[i][j] = s[j - 1] == '0' ? 0 : 1;
            }
        }
    }

    bfs();


    if (dis[0][n][m] == -1 && dis[1][n][m] >= -1){
        cout << dis[1][n][m] << '\n';
    }else if (dis[0][m][m] >= -1 && dis[1][n][m] == -1){
        cout << dis[0][n][m] << '\n';
    }else{
        cout << min(dis[0][n][m], dis[1][n][m]) << '\n';
    }
}
