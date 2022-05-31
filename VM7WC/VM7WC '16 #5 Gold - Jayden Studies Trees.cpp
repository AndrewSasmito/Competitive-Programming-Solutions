#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;



int mx = 0;
int n, x, y;
vector <int> adj[10001];
int dp1[10001], dp2[10001];
int dfs(int parent, int child){

	int first = -1;
	int second = -1;

	for (auto i = adj[child].begin(); i != adj[child].end(); ++i){
		if (*i == parent)
			continue;
		

		dfs (child, *i);


		if (first == -1){
			first = dp1[*i];
		}else if (dp1[*i] >= first){
			second = first;
			first = dp1[*i];
		}else if (dp1[*i] > second){
			second = dp1[*i];
		}
	}

	dp1[child] = 1;
	if (first != -1)
		dp1[child] += first;
	
	if (second != -1)
		dp2[child] = 1 + first + second;

	if (max(dp1[child], dp2[child]) > mx)
		mx = max(dp1[child], dp2[child]);

	return mx;
}

void solve(){
	cin>>n;
	
	for (int i = 0; i<n-1; ++i){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	cout<<dfs(1, 1) - 1<<'\n';
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
