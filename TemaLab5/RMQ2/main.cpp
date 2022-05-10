#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

ifstream fin("rmq.in");
ofstream fout("rmq.out");

const int maxN = 100005;
const int LOG = 20;
int rmq[maxN][LOG],N,M,x,y;

int findMin(int x, int y){
	int h = 0;
	while(1 << (h+1) <= y-x+1){
		h++;
	}
	cout << h << '\n';
	return min(rmq[x][h], rmq[y-(1<<h)+1][h]);
}

int main(){
	fin >> N >> M;
	for(int i = 0; i < N; ++i){
		fin >> rmq[i][0];
	}
	// construiesc sparse table-ul in O(nlog(n))
	for(int j = 1; j < LOG; ++j){
		for(int i = 0; i + (1<<j) - 1 < N; ++i){
			rmq[i][j] = min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]); 
		}
	}
	//raspund in O(m) la toate intrebarile
	for(int i = 0; i < M; ++i){
		fin >> x >> y;
		fout << findMin(x-1,y-1) << '\n';
	}
}