#include <fstream>
#pragma GCC optimize("O3")
		
using namespace std;
	
ifstream fin("datorii.in");
ofstream fout("datorii.out");
	
int arbint[270000], N,x,y,M,op;
int arr[100000];	
	
void create(int st, int dr, int pos){
	if(st == dr){
		arbint[pos] = arr[st-1];
		return;
	}
	int m = (st+dr) >> 1;
	create(st,m, 2*pos);
	create(m+1,dr, 2*pos+1);
	arbint[pos] = arbint[2*pos] + arbint[2*pos+1];
}
	
int sum(int x, int y, int pos, int st, int dr){	
	if(y >= dr && x <= st)
		return arbint[pos];
	else if(dr >= x && st <= y)
		return sum(x,y,2*pos,st,((st+dr)>>1)) + sum(x,y,2*pos+1,((st+dr)>>1)+1,dr);
	return 0;
}
	
void update(int val, int pos, int posInARB, int st, int dr){		
	if(st == dr){
		arbint[posInARB] -= val;
		return;
	}
	if(pos <= ((st+dr)>>1)){
		update(val, pos, posInARB*2, st, ((st+dr)>>1));
		arbint[posInARB] = arbint[posInARB*2] + arbint[posInARB*2 + 1];
		}
	if(pos > ((st+dr)>>1)){
		update(val, pos, posInARB*2 + 1, ((st+dr)>>1)+1, dr);
		arbint[posInARB] = arbint[posInARB*2] + arbint[posInARB*2 + 1];
	}
}
	
int main(){
	ios::sync_with_stdio(false);
	fin.tie(NULL);
	fout.tie(NULL);

	fin >> N >> M;
	for(int i = 0; i < N; ++i){
		fin >> arr[i];
	}
	create(1,N,1);
	for(int i = 0; i < M; ++i){
		fin >> op >> x >> y;
		if(op == 1)
			fout << sum(x,y,1,1,N) << '\n';
		if(op == 0)
			update(y, x, 1, 1, N);
	}
}