#include <bits/stdc++.h>
using namespace std;

int n, dis[1000001];
queue <int> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    q.push(n);
    dis[n] = 1;

    while (q.size()){
        int cur = q.front();
        q.pop();

        if (cur == 1){
            cout << dis[cur] - 1 << '\n';
            return 0;
        }

        if (cur % 3 == 0 && dis[cur / 3] == 0){
            q.push(cur/3);
            dis[cur/3] = dis[cur] + 1;
        }
        if (cur % 2 == 0 && dis[cur / 2] == 0){
            q.push(cur/2);
            dis[cur/2] = dis[cur] + 1;
        }

        if (dis[cur - 1] == 0){
            q.push(cur - 1);
            dis[cur - 1] = dis[cur] + 1;
        }
    }
}
