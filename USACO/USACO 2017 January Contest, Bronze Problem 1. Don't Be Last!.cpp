#include <bits/stdc++.h>
using namespace std;

int n, x;
string st;
set <int> setter;
unordered_set <string> s;
unordered_map <int, int> cnt;
unordered_map <string, int> m;
unordered_map <int, string> here;
vector <int> v;
int main(){
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    cin >> n;
    for (int i = 0; i<n; ++i){
        cin >> st >> x;

        s.insert(st);

        m[st] += x;
    }

    for (string o : s){
        if (n == 1){
            cout << o << '\n';
            return 0;
        }
        setter.insert(m[o]);
        here[m[o]] = o;
        ++cnt[m[o]];
    }

    bool f = 0;

    for (int x : setter){
        if (f == 1){
            if (cnt[x] > 1){
                cout << "Tie\n";
                return 0;
            }else{
                cout << here[x] << '\n';
                return 0;
            }
        }
        f = 1;
    }
    cout << "Tie\n";
}
