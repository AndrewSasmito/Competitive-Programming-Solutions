#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector <int> v[27];


void play(){

	for (int i = 1; i<=50; ++i){
		v[faceup(i) - 'A' + 1].push_back(i);
	}
	//faceup(x);
	

	for (int i = 1; i<=25; ++i){
		faceup(v[i][0]);
		faceup(v[i][1]);
	}
}
