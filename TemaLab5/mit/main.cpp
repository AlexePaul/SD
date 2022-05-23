#include <bits/stdc++.h>

#define FILE "mit"

using namespace std;

ifstream fin(FILE".in");
ofstream fout(FILE".out");

int N,M,op,x,y;
int arr[100005];
int arbint[300005];
int lazy[300005];

void create(int st, int dr, int pos){	
	if(st == dr){
		arbint[pos] = arr[st-1];
		return;
	}
	int m = (st+dr) >> 1;
	create(st,m, 2*pos);
	create(m+1,dr, 2*pos+1);
	arbint[pos] = max(arbint[2*pos],arbint[2*pos+1]);
}
	
	
int getMaxValue(int x, int y, int pos, int st, int dr){	
	if(st > dr)
		return -1;
	if(lazy[pos] != 0){
		arbint[pos] += lazy[pos];
		if(st != dr){
			lazy[pos*2] += lazy[pos];
			lazy[pos*2 + 1] += lazy[pos];
		}
		lazy[pos] = 0;
	}
	if(x > dr || y < st)
		return -1;
	if(y >= dr && x <= st)
		return arbint[pos];
	return max(getMaxValue(x,y,2*pos,st,((st+dr)>>1)),getMaxValue(x,y,2*pos+1,((st+dr)>>1)+1,dr));
}

void update(int val,int pos, int x, int y, int st, int dr){	
	if (lazy[pos] != 0){
        arbint[pos] += lazy[pos];
 		if (st != dr){
            lazy[pos*2] += lazy[pos];
            lazy[pos*2 + 1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
 
    if (st>dr || st>y || dr<x)
        return ;
 
    if (st>=x && dr<=y){
        arbint[pos] += val;
 		if (st != dr){
            lazy[pos*2] += val;
            lazy[pos*2 + 1] += val;
        }
        return;
    }

    int mid = (st+dr)/2;
    update(val, pos*2, x, y, st, mid);
    update(val, pos*2+1, x, y, mid+1, dr);
 
    arbint[pos] = max(arbint[pos*2], arbint[pos*2+1]);
}

int main(){
	ios::sync_with_stdio(false);
	fin >> N;
	fin >> M;
	for(int i = 0; i < N; ++i)
		fin >> arr[i];
	create(1,N,1);

	for(int i = 0; i < M; ++i){
		fin >> op >> x >> y;
		if(op == 1)
			fout << getMaxValue(x,y,1,1,N) << '\n';
		if(op == 2){
			int val;
			fin >> val;
			update(val, 1, x, y, 1, N);
		}
	}
}