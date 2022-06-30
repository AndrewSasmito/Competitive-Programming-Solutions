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

int a, b, tot = 0, speed = 1, cur;
bool f = 0;

void solve(){
	cin >> a >> b;

	cur = a;
	if (a == b){
		cout << 0 << '\n';
		return;
	}
	while (true){
		if (f == 0){
			if (a + speed >= b && b > a){
				tot += b - cur;
				break;
			}
			
			tot += (a + speed) - cur;
			cur = a + speed;

		}else{
			if (a - speed <= b && b < a){
				tot += abs(b - cur);
				break;
			}
			tot += cur - (a - speed);
			cur = a - speed;
		}
		//cout << tot << '\n';
		f = 1 - f;
		speed *= 2;
	}

	cout << tot << '\n';
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

	usaco();


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
