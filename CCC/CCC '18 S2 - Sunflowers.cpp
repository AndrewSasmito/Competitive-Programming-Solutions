#include <bits/stdc++.h>
using namespace std;

vector <int> v[101];

int n, x;
int main() {
    cin >> n;
    
    for (int i = 0; i<n; ++i){
        for (int j = 0; j<n; ++j){
            cin >> x;
            v[i].push_back(x);
        }
    }
    
    if (v[0][0] < v[n-1][0] && v[0][0] < v[n-1][n-1] && v[0][0] < v[0][n-1]){
        for (int i = 0; i<n; ++i){
            for (int j = 0; j<n; ++j){
                cout << v[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    else if (v[n-1][0] < v[0][0] && v[n-1][0] < v[n-1][n-1] && v[n-1][0] < v[0][n-1]){

                for (int i = 0; i<n; ++i){
            for (int j = n-1; j>=0; --j){
                cout << v[j][i] << ' ';
            }
            cout << '\n';
        }
    }
    else if (v[n-1][n-1] < v[n-1][0] && v[n-1][n-1] < v[0][0] && v[n-1][n-1] < v[0][n-1]){
        for (int i = n-1; i>=0; --i){
            for (int j = n-1; j>=0; --j){
                cout << v[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    else {
        for (int i = n-1; i>=0; --i){
            for (int j = 0; j<n; ++j){
                cout << v[j][i] << ' ';
            }
            cout << '\n';
        }
    }
}
