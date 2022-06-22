#include <bits/stdc++.h>
using namespace std;
//runtime
clock_t __init_time__ = clock();
#define elapsedTime ((double)(clock()-__init_time__)/CLOCKS_PER_SEC)<<" seconds"
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, x;
void solve(){
	cin >> n;

	deque <int> v;

	for (int i = 0; i<n; ++i){
		cin >> x;
		v.push_back(x);
	}
	ll atot = v.front(), btot = 0, cur = 0, mx = v.front(), rnd = 1;
	bool f = 1;
	v.pop_front();

	while (v.size()){
		if (f == 1){
			if (cur > mx){
				++rnd;
				f = 1 - f;
				btot += cur;
				mx = cur;
				cur = 0;
			}else{
				cur += v.back();
				v.pop_back();
			}
		}else if (f == 0){
			if (cur > mx){
				++rnd;
				f = 1 - f;
				atot += cur;
				mx = cur;
				cur = 0;
			}else{
				cur += v.front();
				v.pop_front();
			}
		}
	}
	
	if (f == 1 && cur > 0){
		btot += cur;
		++rnd;
	}else if (f == 0 && cur > 0){
		atot += cur;
		++rnd;
	}

	cout << rnd << ' ' << atot << ' ' << btot << '\n';
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
	cin >> testcases; 
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
    


    //Google
    //cout<<"Case #"<<number_of_total_test_cases<<": ";
    // Normal
    solve();
    }

	//cout << elapsedTime << '\n';
}
