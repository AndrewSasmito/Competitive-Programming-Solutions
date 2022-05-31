#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define forloop(i,a,b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
typedef pair<int, int> pii;
typedef vector<int> vi;



bool cat[26][26];
void solve(){
	int r, c, k;
	cin>>r>>c>>k;
	
	int grid[26][26];


	for (int i = 0; i<k; ++i){
		int row, col;
		cin>>row>>col;

		grid[row][col] = 0;
		cat[row][col] = 1;
	}
	



	grid[1][1] = 1;

	for (int j = 1; j<r+1; ++j){
		for (int i = 1; i<c+1; ++i){

			if (cat[j][i] == 1){
				continue;
			}
			else if (j == 1 and i == 1){
				continue;
			}
			else if (j==1){
				grid[j][i] = grid[j][i-1];
				continue;
			}else if (i == 1){
				grid[j][i] = grid[j-1][i];
				continue;
			}
			
			grid[j][i] = grid[j-1][i] + grid[j][i-1];
		}
	}

	cout<<grid[r][c];

}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int main(){
	solve();
}
