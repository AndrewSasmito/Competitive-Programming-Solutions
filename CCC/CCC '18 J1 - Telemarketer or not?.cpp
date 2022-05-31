#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int x, y, ans = 0;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scan(x);
	if (x == 8 || x == 9)
		++ans;
	scan(x); scan(y);
	if (x == y)
		++ans;
	
	scan(y);
	if (y == 8 || y == 9)
		++ans;
	
	cout<<(ans == 3 ? "ignore" : "answer")<<'\n';

}
