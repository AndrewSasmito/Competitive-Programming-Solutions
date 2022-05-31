#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int dp[500001], n, dis[500001];
queue <int> q;
int calc(int x){
	if (dp[x] > 0){
		return dp[x];
	}
	else{
		return dp[x] = (calc(x - 1) + calc(x-2))%2021;
	}
}
void solve(){
	dp[1] = 1;
	dp[2] = 1;
	
	cin >> n;

	q.push(1);

	while (q.size()){
		int cur = q.front();
		q.pop();
		
		if (dis[n] > 0){
			cout << dis[n] << '\n';
			break;
		}
		//cout << cur << ' ' << calc(cur) << ' ' << cur % 50 << '\n';

		if (cur + calc(cur) + (cur % 50) <= n)
			if (dis[cur + calc(cur) + (cur % 50)] == 0){
				dis[cur + calc(cur) + (cur % 50)] = dis[cur] + 1;
				q.push(cur + calc(cur) + (cur % 50));
			}

		if (cur - calc(cur) - (cur % 50) > 0)
			if (dis[cur - calc(cur) - (cur % 50)] == 0){
				dis[cur - calc(cur) - (cur % 50)] = dis[cur] + 1;
				q.push(cur - calc(cur) - (cur % 50));
			}

		if (cur + 1 <= n)
			if (dis[cur + 1] == 0){
				dis[cur + 1] = dis[cur] + 1;
				q.push(cur + 1);
			}


		if (cur - 1 > 0)
			if (dis[cur - 1] == 0){
				dis[cur - 1] = dis[cur] + 1;
				q.push(cur - 1);
			}
	}
}
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

}
