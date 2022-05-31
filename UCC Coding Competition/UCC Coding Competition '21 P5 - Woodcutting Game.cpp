#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int h1, w1, h2, w2;
bool dp[3][301][3][301];
bool vis[3][301][3][301];

bool calc (int h1, int w1, int h2, int w2){
	if (h1 == 1 && w1 == 1 && h2 == 1 && w2 == 1)
		return 0;
	if (vis[h1][w1][h2][w2])
		return dp[h1][w1][h2][w2];

	vis[h1][w1][h2][w2] = 1;
	bool val = 0;


	for (int k = 1; k<w1; ++k){
		val |= !calc(h1, k, h1, w1 - k);
	}
	for (int k = 1; k<w2; ++k){
		val |= !calc(h2, k, h2, w2 - k);
	}

	if (h1 == 2)
		val |= !calc(1, w1, 1, w1);
	if (h2 == 2)
		val |= !calc(1, w2, 1, w2);

	for (int k = 1; k<=10 && k < w1; ++k){
		val |= !calc (h1, w1-k, h2, w2);
	}
	for (int k = 1; k<=10 && k < w2; ++k){
		val |= !calc (h1, w1, h2, w2 - k);
	}
	if (h1 == 2)
		val |= !calc(1, w1, h2, w2);
	if (h2 == 2)
		val |= !calc(h1, w1, 1, w2);
	
	return dp[h1][w1][h2][w2] = val;
}

void solve(){
	cin >> h1 >> w1 >> h2 >> w2;

	cout << (calc(h1, w1, h2, w2) == 1 ? 'W' : 'L') << '\n';
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
