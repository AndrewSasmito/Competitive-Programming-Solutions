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
int a, b, c, d;
bool dp[31][31][31][31];
int mover[6][5] = {{2, 1, 0, 2}, {1, 1, 1, 1}, {0, 0, 2, 1}, {0, 3, 0, 0}, {1, 0, 0, 1}};
void solve(){
	for (int as = 0; as < 31; ++as){
		for (int bs = 0; bs < 31; ++bs){
			for (int cs = 0; cs < 31; ++cs){
				for (int ds = 0; ds < 31; ++ds){
					for (int k = 0; k < 5; ++k){
						if (mover[k][0] <= as && mover[k][1] <= bs && mover[k][2] <= cs && mover[k][3] <= ds){
							if (!dp[as-mover[k][0]][bs-mover[k][1]][cs-mover[k][2]][ds-mover[k][3]])
								dp[as][bs][cs][ds] = true;
						}
					}
				}
			}
		}
	}
}
void solver(){
	cin >> a >> b >> c >> d;
	
	cout << (dp[a][b][c][d] == false ? "Roland" : "Patrick") << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	solve();

    int testcases = 1;
   	cin >> testcases;
    for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
    

    //Google
    //cout<<"Case #"<<number_of_total_test_cases<<": ";:
    // Normal
    solver();
    }

}
