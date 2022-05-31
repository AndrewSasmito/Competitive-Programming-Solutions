#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;
string s;
vector <string> adj;
vector <string> noun;
int main() {
    cin >> n >> m;
    
    for (int i = 0; i<n; ++i){
        cin >> s;
        adj.push_back(s);
    }
    for (int i = 0; i<m; ++i){
        cin >> s;
        noun.push_back(s);
    }
    
    for (string f : adj){
        for (string s : noun){
            cout << f << " as " << s << '\n';
        }
    }
}
