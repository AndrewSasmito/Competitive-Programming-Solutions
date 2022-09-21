#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const ll X = 131, Y = 47, MOD = 1e9 + 3;
unordered_set <ll> ans;
string s, t;
int cnt[26], cur[26], hsh2 = 0, hsh1 = 0;

bool check(){
    for (int i = 0; i < 26; ++i){
        if (cnt[i] != cur[i]){
            return 0;
        }
    }
    return 1;
}

int fpow(int b, int p) {
    if (p == 0) return 1;
    int half = fpow(b, p / 2);
    if (p % 2 == 0) return half * half % MOD;
    else return half * half % MOD * b % MOD;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> t >> s;
    if (t.size() > s.size()){
        cout << 0 << '\n';
        return 0;
    }


    for (int i = 0; i<t.size(); ++i){
        ++cnt[t[i] - 'a'];
    }

    for (int i = 0; i<t.size(); ++i){
        ++cur[s[i] - 'a'];
        hsh1 *= X; hsh2 %= MOD; hsh1 += s[i] - 'a' + MOD; hsh1 %= MOD;
        
        hsh2 *= Y; hsh2 %= MOD; hsh2 += s[i] - 'a' + MOD; hsh2 %= MOD;
    }
    if (check()){
        ans.insert((hsh2 * MOD) + hsh1);
    }
    for (int i = t.size(); i < s.size(); ++i){
        ++cur[s[i] - 'a'];
        --cur[s[i - t.size()] - 'a'];

        hsh1 *= X; hsh1 %= MOD; hsh1 -= fpow(X, t.size()) * (s[i-t.size()] - 'a'); hsh1 %= MOD; hsh1 += s[i] - 'a' + MOD; hsh1 %= MOD;
        
        hsh2 *= Y; hsh2 %= MOD; hsh2 -= fpow(Y, t.size()) * (s[i-t.size()] - 'a'); hsh2 %= MOD; hsh2 += s[i] - 'a' + MOD; hsh2 %= MOD;


        if (check()){
            ans.insert((hsh2 * MOD) + hsh1);
        }
    }

    cout << ans.size() << '\n';
}
