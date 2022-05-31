#include <iostream>
using namespace std;
int main() {
  int a, b, t=0, f, l=0;
  cin>>a;
  cin>>b;
  cout<<"The number of RSA numbers between "<<a;
  while (a<b+1){
      f=0;
  for (t=1; t<a+1; t++){
    if (a%t==0){
      f++;
    }
  }
  if (f==4){
    l++;
  }
    a++;
    }
  cout<<" and "<<b<<" is "<<l << '\n';
}
