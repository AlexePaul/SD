#include <fstream>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;

ifstream fin("rmq.in");
ofstream fout("rmq.out");

int rmq[100005]; int N,x,y,M;
int arr[100000];

void create(int st, int dr, int pos){
	if(st == dr){
		rmq[pos] = arr[st-1];
		return;
	}
	int m = (st+dr) >> 1;
	create(st,m, 2*pos);
	create(m+1,dr, 2*pos+1);
	rmq[pos] = min(rmq[2*pos],rmq[2*pos+1]);
}

int getMinValue(int x, int y, int pos, int st, int dr){
	if(x <= st && y >= dr)
		return rmq[pos];
	else if(x > dr || y < st)
		return 2147483647;
	return min(getMinValue(x,y,2*pos,st,((st+dr)>>1)),getMinValue(x,y,2*pos+1,((st+dr)>>1)+1,dr));
	
}

int main(){
	ios::sync_with_stdio(false);
	fin >> N >> M;
	for(int i = 0; i < N; ++i){
		fin >> arr[i];
	}
	create(1,N,1);
	for(int i = 0; i < M; ++i){
		fin >> x >> y;
		fout << getMinValue(x,y,1,1,N) << '\n';
	}
	
}