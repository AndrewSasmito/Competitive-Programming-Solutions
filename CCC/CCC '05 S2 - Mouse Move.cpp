#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int x, y, a = 0, b = 0, i, j;
void solve(){
	cin >> x >> y;

	while (true){
		cin >> i >> j;

		if (i == 0 && j == 0)
			return;

		a = min(x, max(0, a + i));
		b = min(y, max(0, b + j));
		cout << a << ' ' << b << '\n';
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
