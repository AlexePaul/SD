#include <fstream>
#include <vector>
#include "fibHeap.h"
#include "fibHeap.cpp"

using namespace std;

ifstream fin("mergeheap.in");
ofstream fout("mergeheap.out");

int main(){
	int n, q, op, m, a, b, x;
	vector< fibHeap<int> > heaps;
	fin >> n >> q;
	heaps.resize(n+5);
	for(int i = 0; i < q; ++i){
		fin >> op;
		if(op == 1){
			fin >> m >> x;
			heaps[m].insert(x);
			continue;
		}
		if(op == 2){
			fin >> m;
			fout << heaps[m].removeMax() << '\n';
			continue;
		}
		if(op == 3){
			fin >> a >> b;
			heaps[a].merge(heaps[b]);
			heaps[b].empty();
		}
	}
}