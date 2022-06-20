#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


int n, x, s1 = 0, s2 = 0, s3 = 0, s4 = 0, ans = 0;
void solve(){
	cin >> n;

	for (int i = 0; i<n; ++i){
		cin >> x;
		if (x == 1){
			++s1;
		}else if (x == 2){
			++s2;
		}else if (x == 3){
			++s3;
		}else{
			++s4;
		}
	}
	ans += s4;

	ans += s3;

	s1 = max(0, s1 - s3);

	ans += s2 / 2;

	if (s2 % 2 == 1){
		++ans;

		s1 = max(0, s1 - 2);
	}

	ans += s1 / 4;

	if (s1 % 4 != 0 && s1 > 0){
		++ans;
	}
	cout << ans << '\n';
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
