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
	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);
}


int a, b;
vector <int> cap;
vector <int> cur;
void solve(){
	for (int i = 0; i<3; ++i){
		cin >> a >> b;
		cap.push_back(a);
		cur.push_back(b);
	}

	int pos = 0, temp, next = 1;
	for (int i = 0; i<100; ++i){
		temp = cur[pos];
		cur[pos] -= (cap[next] - cur[next]);
		cur[pos] = max(cur[pos], 0);

		cur[next] += temp;
		cur[next] = min(cap[next], cur[next]);

		++pos;
		++next;

		pos %= 3;
		next %= 3;
		/*
		for (int i = 0; i<3; ++i){
			cout << cur[i] << ' ';
		}
		cout << '\n';
		cout << pos << ' ' << next << '\n';
		*/
	}

	for (int i = 0; i<3; ++i){
		cout << cur[i] << '\n';
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
