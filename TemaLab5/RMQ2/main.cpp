#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

ifstream fin("rmq.in");
ofstream fout("rmq.out");

int rmq[100005][100005]={INT_MAX},N,M,x,y;

int main(){
	fin >> N >> M;
	for(int i = 0; i < N; ++i){
		fin >> x;
		for(int j = 0; j <= i+1; ++i){
			rmq[i][j] = min(rmq[i-1][j],x);
		}
	}
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cout << rmq[i][j] << ' ';
		}
		cout << '\n';
	}
}