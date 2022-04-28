#include <bits/stdc++.h>

#define FILE "proc2"

using namespace std;

ifstream fin(FILE".in");
ofstream fout(FILE".out");

priority_queue <int, vector<int>, greater<int> > nonw; 
priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > working; 

int n,m;
int s,d;

int main(){
	fin >> n >> m;
	for(int i = 1; i <= n; ++i){
		nonw.push(i);
	}
	for(int i = 0; i < m; ++i){
		fin >> s >> d;
		while(!working.empty() && working.top().first <= s){
			nonw.push(working.top().second);
			working.pop();
		}
		fout << nonw.top() << '\n';
		working.push(make_pair(s+d, nonw.top()));
		nonw.pop();

	}
}