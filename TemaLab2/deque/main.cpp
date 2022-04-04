#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("deque.in");
ofstream fout("deque.out");

pair<long,long> q[100000000];
long long n,l,sum,x,size,inceput;

void push_back(pair<long long, long long> tmp){
	q[size] = tmp;
	size++;
}

void pop_back(){
	size--;
}

pair<long long, long long> back(){
	return q[size-1];
}

bool empty(){
	if(size == inceput)
		return true;
	return false;
}

pair<long long, long long> front(){
	return q[inceput];
}

void pop_front(){
	inceput++;
}

int main(){
fin >> n;
fin >> l;
for(int i = 1; i <= n; ++i){
	fin >> x;
	while(empty() == false && back().first >= x)
		pop_back();
	push_back({x,i});
	if(i >= l){
		sum += front().first;
	} 
	if(i >= front().second + l - 1){
		pop_front();
	}
}
fout << sum;
}