#include <bits/stdc++.h>
using namespace std;

int hcnt = 0, scnt = 0;
string s;
int main(){
    getline(cin, s);
    
    for (int i = 0; i<s.size() - 2; ++i){
        if (s[i] == ':' && s[i + 1] == '-'){
            if (s[i + 2] == '(')
                ++scnt;
            else if (s[i + 2] == ')')
                ++hcnt;
        }
    }
    
    if (scnt == 0 && hcnt == 0){
        cout << "none\n";
    }else if (scnt == hcnt){
        cout << "unsure\n";
    }else if (scnt > hcnt){
        cout << "sad\n";
    }else{
        cout << "happy\n";
    }
}
