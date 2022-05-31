#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int x, y;
void solve(){
	cin >> x >> y;

	if (x < 0 && y < 0){
		cout << 3 << '\n';
	}else if (x < 0 && 0 < y){
		cout << 2 << '\n';
	}else if (0 < x && y < 0){
		cout << 4 << '\n';
	}else{
		cout << 1 << '\n';
	}
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
