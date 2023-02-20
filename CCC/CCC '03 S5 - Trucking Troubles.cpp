#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int c, r, d, x, y, z, par[100001], score[100001], firster, seconder, ans = 999999;
bool cities[100001];
int parent(int n){
	return n == par[n] ? n : par[n] = parent(par[n]);
}
void solve(){
	cin >> c >> r >> d;
	

	vector <int> destination;

	priority_queue <pair<int, pair<int, int>>, vector <pair <int, pair <int, int>>>> q;
	for (int i = 1; i <= r; ++i){
		cin >> x >> y >> z;
		
		q.push({z, {x, y}});
	}
	for (int i = 1; i<=c; ++i){
		par[i] = i;
		score[i] = 9999999;
	}

	for (int i = 0; i<d; ++i){
		cin >> x;
		destination.push_back(x);
	}
	destination.push_back(1);
	while (q.size()){
		x = q.top().second.first;
		y = q.top().second.second;
		z = q.top().first;
		//cout << x << ' ' << y << ' ' << z << '\n';
		q.pop();
		firster = parent(x);
		seconder = parent(y);
		if (firster != seconder){
			cities[x] = 1;
			cities[y] = 1;
			
			bool f = 1;

			
			par[seconder] = firster;
			score[firster] = min(score[seconder], z);
			for (int i = 0; i<destination.size(); ++i){
				if (cities[destination[i]] == 0){
					f = 0;
					break;
				}
			}

			if (f == 1)
				break;
		}
	}
	ans = score[parent(destination[0])];
	cout << ans << '\n';
}


int main(){
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int testcases = 1;
    //cin >> testcases;
    for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
    

    //Google
    //cout<<"Case #"<<number_of_total_test_cases<<": ";
    // Normal
    solve();
    }

}
