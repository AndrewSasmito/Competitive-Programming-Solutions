#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

void usaco(){
	freopen("lostcow.in", "r", stdin);
	freopen("lostcow.out", "w", stdout);
}

//do not submit if usaco(); is open

double c, s, p, n, x, y, z, tot, ans = 0;

vector <double> code;
vector <double> sick;
vector <double> path;
void solve(){
	cin >> c >> s >> p >> n;

	for (int i = 0; i<n; ++i){
		cin >> x >> y >> z;
		code.push_back(x);
		sick.push_back(y);
		path.push_back(z);
	}
	x = 0, y = 0, z = 0;
	if (n <= 5){
		for (int i = 0; i<n; ++i){
			x += code[i];
			y += sick[i];
			z += path[i];
		}

		printf("%.1f\n", min((double)100, min(x / c, min(y/s, z/p)) * 100));
		return;
	}else{
		for (int i = 0; i<n; ++i){
			for (int j = i + 1; j < n; ++j){
				for (int k = j + 1; k < n; ++k){
					for (int l = k + 1; l < n; ++l){
						for (int m = l + 1; m < n; ++m){
						    x = 0, y = 0, z = 0;
							x += code[i] + code[j] + code[k] + code[l] + code[m];
							y += sick[i] + sick[j] + sick[k] + sick[l] + sick[m];
							z += path[i] + path[j] + path[k] + path[l] + path[m];

							ans = max(ans, min(x/c, min(y/s, z/p)));
							x = 0, y = 0, z = 0;
						}
					}
				}
			}
		}

		printf("%.1f\n", min((double)100, ans * 100));
	}
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//usaco();


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
