#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int ins[8], x, y;
vector <int> adj[8];
vector <int> v;
priority_queue <int, vector<int>, greater<int>> q;
void solve(){

	adj[1].push_back(7);
	++ins[7];
	adj[1].push_back(4);
	++ins[4];
	adj[2].push_back(1);
	++ins[1];
	adj[3].push_back(4);
	++ins[4];
	adj[3].push_back(5);
	++ins[5];

	while (true){
		scan(x);
		scan(y);

		if (x == 0 && y == 0)
			break;

		adj[x].push_back(y);
		++ins[y];
	}


	for (int i = 1; i<=7; ++i){
		if (ins[i] == 0){
			q.push(i);
		}
	}
	
	while (q.size()){
		int cur = q.top();
		v.push_back(cur);
		q.pop();

		for (int x : adj[cur]){
			--ins[x];

			if (ins[x] == 0){
				q.push(x);
			}
		}
	}

	for (int i = 1; i<=7; ++i){
		if (ins[i] > 0){
			cout << "Cannot complete these tasks. Going to bed.\n";
			return;
		}
	}

	for (int x : v){
		cout << x << ' ';
	}
	cout << '\n';
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
