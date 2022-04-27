#include <fstream>
#include <iostream>
#include <deque>
#define FILE "branza"
#define int long long

using namespace std;

ifstream fin(FILE".in");
ofstream fout(FILE".out");

deque<int> q;
int n,t,s,sum,kg;
int cost[1000000]; 

int32_t main(){
	fin >> n >> s >> t;

	for (int i = 0; i < n; ++i){
		fin >> cost[i] >> kg;
		if(!q.empty() && q.front() == i-t-1)
			q.pop_front();
		while(!q.empty() && cost[q.back()] + (i - q.back()) * s >= cost[i])
			q.pop_back();
		q.push_back(i);
		sum += 	kg * (cost[q.front()] + (i-q.front()) * s);	
	}

	fout << sum;
}