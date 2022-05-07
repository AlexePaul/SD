#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#define FILE "pariuri"
#define int long long

using namespace std;

ifstream fin(FILE".in");
ofstream fout(FILE".out");

int n,m,x,y;
unordered_map<int,int> umap;
unordered_set<int> uset;
int countNr;

int32_t main(){
	ios::sync_with_stdio(false);
	fin >> n;
	for(int i = 0; i < n; ++i){
		fin >> m; 
		for(int i = 0; i < m; ++i){
			fin >> x >> y;
			uset.insert(x);
			umap[x] += y;
		}
	}
	fout << uset.size() << '\n';
	
	for(auto& it: umap){
		fout << it.first <<' '<< it.second << ' ';
	}
}