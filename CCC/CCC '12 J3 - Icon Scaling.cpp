#include <bits/stdc++.h>
using namespace std;

string s1 = "*x*", s2 = " xx", s3 = "* *";
int n;
int main(){
    scanf("%d", &n);
    
    for (int j = 0; j<n; ++j){
        for (int z = 0; z < s1.size(); ++z){
            for (int i = 0; i<n; ++i){
                cout << s1[z];
            }         
        }
        cout << '\n';
    }

    for (int j = 0; j<n; ++j){
        for (int z = 0; z < s2.size(); ++z){
            for (int i = 0; i<n; ++i){
                cout << s2[z];
            }         
        }
        cout << '\n';
    }
    
    for (int j = 0; j<n; ++j){
        for (int z = 0; z < s3.size(); ++z){
            for (int i = 0; i<n; ++i){
                cout << s3[z];
            }         
        }
        cout << '\n';
    }
}
