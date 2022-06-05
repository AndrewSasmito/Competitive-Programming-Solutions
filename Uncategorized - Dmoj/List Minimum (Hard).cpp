#include <bits/stdc++.h>

using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
set <int> s;
int n, x;
int main() {
    scan(n);
    for (int i = 0; i<n; ++i){
        scan(x);
        s.insert(x);
    }
    for (int a : s){
        printf("%d\n", a);
    }
}
