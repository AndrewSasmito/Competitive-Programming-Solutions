#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int a, b, c;
unordered_set <int> s;
void solve(){
	cin >> a >> b >> c;

	s.insert(a);
	s.insert(b);
	s.insert(c);

	if (a + b + c != 180){
		cout << "Error\n";
	}else{
		if (s.size() == 1){
			cout << "Equilateral\n";
		}else if (s.size() == 2){
			cout << "Isosceles\n";
		}else{
			cout << "Scalene\n";
		}
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
