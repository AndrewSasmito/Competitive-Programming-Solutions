#include <bits/stdc++.h>
using namespace std;

string s, cur;
int n;
bool f;
unordered_map <string, bool> m;
int main(){
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    cin >> n >> s;

    for (int i = 1; i<s.size(); ++i){
       f = 1;

       for (int j = 0; j<s.size() - i + 1; ++j){
            cur = "";
            for (int k = j; k < j + i; ++k){
                cur += s[k];
            }

            if (m[cur] == 1){
                f = 0;
                break;
            }else{
                m[cur] = 1;
            }
       }
        if (f == 1){
            cout << i << '\n';
            return 0;
        }

        m.clear();
    }
    cout << s.size() + 1 << '\n';
}
