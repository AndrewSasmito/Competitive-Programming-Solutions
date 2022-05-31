#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int n, ans;
int main(){
	scan(n);
	ans = 5 * n - 400;
	if (ans == 100)
		printf("%d\n0\n", ans);
	else if (ans < 100)
		printf("%d\n1\n", ans);
	else
		printf("%d\n-1\n", ans);
}
