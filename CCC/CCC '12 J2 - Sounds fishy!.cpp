#include <iostream>
#include <vector>

using namespace std;
vector <int> v;
int x;
int main(){
    for (int i = 0; i<4; ++i){
        cin >> x;
        v.push_back(x);
    }
    
    if (v[0] == v[1] && v[1] == v[2] && v[2] == v[3]){
        cout << "Fish At Constant Depth\n";
    }else if (v[0] < v[1] && v[1] < v[2] && v[2] < v[3]){
        cout << "Fish Rising\n";
    }else if (v[0] > v[1] && v[1] > v[2] && v[2] > v[3]){
        cout << "Fish Diving\n";
    }else{
        cout << "No Fish\n";
    }
}
