#include <fstream>
#include <iostream>
#include <deque>
#define FILE "branza"

using namespace std;

ifstream fin(FILE".in");
ofstream fout(FILE".out");

struct element{
	long long kg;
	long long cost;
	long long sapt;
};

deque<element> q;
int n,t,s,c,p,sum;
element array[1000000]; 

int main(){
	fin >> n >> s >> t;
	
	for(int i = 0; i < n; ++i){
		fin >> array[i].cost >> array[i].kg;
		array[i].sapt = i; 
	}

	for(int i = n-1; i >= 0; --i){
		while(!q.empty() && array[i].cost + s * (q.back().sapt - i) < q.back().cost && (q.back().sapt - i) <= t){
			sum += s * (q.back().sapt - i) * q.back().kg;
			array[i].kg += q.back().kg;
			q.pop_back();
		}
		q.push_back(array[i]);
	}
	
	while(!q.empty()){
		cout << q.front().kg << ' ' << q.front().cost << '\n';
		sum += q.front().kg * q.front().cost;
		q.pop_front();
	}

	fout << sum;
}