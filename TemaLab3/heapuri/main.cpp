#pragma GCC optimize("O3")

#include <bits/stdc++.h>

#define FILE "heapuri"

using namespace std;

ifstream fin(FILE".in");
ofstream fout(FILE".out");

pair<int,int> heap[200005];
int posinH[200005];
int n,x,op,size,k=1;

void urca(int x){
	int pos = x;
	while(pos > 0){
		if(heap[pos/2].first > heap[pos].first){
			swap(posinH[heap[pos/2].second],posinH[heap[pos].second]);
			swap(heap[pos/2],heap[pos]);
			pos /= 2;
		}
		else{
			break;
		}
	}
}

void heapify(int i)
{
  int smallest = i;
  int l = 2 * i;
  int r = 2 * i + 1;
  if (l < size && heap[l].first < heap[smallest].first)
    smallest = l;
  if (r < size && heap[r].first < heap[smallest].first)
    smallest = r;

  if (smallest != i)
  {
  	swap(posinH[heap[i].second],posinH[heap[smallest].second]);
    swap(heap[i], heap[smallest]);
    heapify(smallest);
  }
}

void insert(int x){
	int pos = size+1;
	pair<int,int> xp = {x, k};
	posinH[k] = pos;
	k++;
	heap[pos] = xp;
	urca(pos);
	
}

void remove(int x){
	int pos=0;
	pos = posinH[x];
	heap[pos] = heap[size];
	posinH[heap[pos].second] = pos;
	urca(pos);
	heapify(pos);
}

int main(){
	fin >> n;
	ios::sync_with_stdio(false);
	for(int i = 0; i < n; ++i){
		fin >> op;
		switch (op){
			case 1:
				fin >> x;
				insert(x);
				size++;
				break;
			case 2:
				fin >> x;
				remove(x);
				size--;
				break;
			case 3:
				fout << heap[1].first << '\n';
				break;
			default:
				break;	
		}	
	}
}