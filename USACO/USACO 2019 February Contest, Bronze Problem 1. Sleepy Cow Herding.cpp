#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

vector <ll> v;
int main(){

    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    for (int i = 0, x; i < 3; ++i){
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    if (v[1] - v[0] == 1 && v[2] - v[1] == 1){
        cout << 0 << '\n' << 0 << '\n';
    }else if (v[1] - v[0] <= 2 || v[2] - v[1] <= 2){
        cout << 1 << '\n' << 2 << '\n';
    }else{
        cout << 2 << '\n' << 2 << '\n';
    }
}
