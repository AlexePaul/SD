#include <fstream>
#pragma GCC optimize("O3")

using namespace std;

ifstream fin("rmq.in");
ofstream fout("rmq.out");

int rmq[270000]; int N,x,y,M;

void insert(int val, int pos, int posInRMQ, int st, int dr){
	if(st == dr){
		rmq[posInRMQ] = val;
		return;
	}
	if(pos <= ((st+dr)>>1)){
		insert(val, pos, (posInRMQ<<1), st, ((st+dr)>>1));
		rmq[posInRMQ] = min(rmq[(posInRMQ<<1)], rmq[(posInRMQ<<1) + 1]);
		}
	if(pos >= ((st+dr)>>1)){
		insert(val, pos, (posInRMQ<<1) + 1, ((st+dr)>>1)+1, dr);
		rmq[posInRMQ] = min(rmq[(posInRMQ<<1)], rmq[(posInRMQ<<1) + 1]);
	}
}

int getMinValue(int x, int y, int pos, int st, int dr){
	if(y >= dr && x <= st)
		return rmq[pos];
	else if(dr >= x && st <= y)
		return min(getMinValue(x,y,2*pos,st,((st+dr)>>1)),getMinValue(x,y,2*pos+1,((st+dr)>>1)+1,dr));
	return 2147483647;
	
}

int main(){
	ios::sync_with_stdio(false);
	fin >> N >> M;
	for(int i = 0; i < N; ++i){
		fin >> x;
		insert(x, i, 1, 0, N-1);
	}
	for(int i = 0; i < M; ++i){
		fin >> x >> y;
		fout << getMinValue(x,y,1,1,N) << '\n';
	}
	
}