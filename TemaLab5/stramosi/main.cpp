#include <bits/stdc++.h>
	
#define FILE "stramosi"
	
using namespace std;
	
ifstream fin(FILE".in");
ofstream fout(FILE".out");
	
const int maxN = 400000;
const int maxL = 22;
	
int m[maxL+5][maxN+5];
int N,M,x,y;
	
int prelucrare(int x, int y){
	int sol = x;
	int c = 0;
	while(y != 0){
		if(y%2 == 1){
			sol = m[c][sol];
		}
		c++;
		y>>=1;
	}
	return sol;
}
	
int main(){		
	ios::sync_with_stdio(false);
	fin >> N >> M;
	for(int i = 1; i <= N; ++i){
		fin >> m[0][i];
	}
	for(int j = 1; j < maxL; ++j){
		for(int i = 1; i <= N; ++i){
			m[j][i] = m[j-1][m[j-1][i]];
		}
	}
	
	for(int i = 0; i < M; ++i){	
		fin >> x >> y;
		fout << prelucrare(x,y) << '\n';
	}
}