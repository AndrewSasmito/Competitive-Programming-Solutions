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
int n;
ll alice, bob, x;
void solve(){
	cin >> n;
	
	priority_queue <ll, vector<ll>> evn;
	priority_queue <ll, vector<ll>> odd;

	for (int i = 0; i<n; ++i){
		cin >> x;

		if (x % 2 == 0){
			evn.push(x);
		}else{
			odd.push(x);
		}
	}
	
	bool f = 0;
	alice = 0;
	bob = 0;

	while (true){
		if (odd.size() == 0 && evn.size() == 0){
			break;
		}
		if (f == 0){
			if (odd.size() == 0){
				alice += evn.top();
				evn.pop();
			}else if (evn.size() == 0){
				odd.pop();
			}else{

				if (evn.top() > odd.top()){
					alice += evn.top();
					evn.pop();
				}else{
					odd.pop();
				}
			}
		}else{
			if (odd.size() == 0){
				evn.pop();
			}else if (evn.size() == 0){
				bob += odd.top();
				odd.pop();
			}else{

				if (evn.top() > odd.top()){
					evn.pop();
				}else{
					bob += odd.top();
					odd.pop();
				}
			}

		}
		f = 1 - f;
	}

	if (alice == bob){
		cout << "Tie\n";
	}else if (alice > bob){
		cout << "Alice\n";
	}else{
		cout << "Bob\n";
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
	cin >> testcases; 
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
    


    //Google
    //cout<<"Case #"<<number_of_total_test_cases<<": ";
    // Normal
    solve();
    }

	//cout << elapsedTime << '\n';
}
