#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n;
void solve(){
	cin >> n;
	
	ll round = 0, win = n, lose = 0, gone = 0, half;

	while (true){
		bool w = 0, l = 0;
		cout << "Round " << round << ": " << win << " undefeated, " << lose << " one-loss, " << gone << " eliminated\n";

		if ((win == 1 && lose == 0) || (win == 0 && lose == 1)){
			break;
		}else if ((win == 1 && lose == 1)){
			--win;
			++lose;
			++round;
			continue;
		}

		if (win % 2 == 1){
			w = 1;
		}
		if (lose % 2 == 1){
			l = 1;
		}
		
		gone += lose/2;
		
		lose /= 2;

		lose += win/2;
		
		win /= 2;

		if (w == 1)
			++win;
		if (l == 1)
			++lose;

		++round;
	}

	cout << "There are " << round << " rounds.\n";
}






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
}
