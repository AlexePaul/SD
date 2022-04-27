#include <bits/stdc++.h>
#include <unordered_map>

#define FILE "loto"

using namespace std;

ifstream fin(FILE".in");
ofstream fout(FILE".out");

struct data{
	int value;
	int nr1, nr2, nr3;
};
int n,s;
unordered_map<int,data> umap;
int numbers[105];

int main(){
	ios::sync_with_stdio(false);
	fin >> n;
	fin >> s;
	for(int i = 0; i < n; ++i)
		fin >> numbers[i];
	for(int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j)
			for (int k = j; k < n; ++k){
				umap[numbers[i]+numbers[j]+numbers[k]].value++;
				umap[numbers[i]+numbers[j]+numbers[k]].nr1 = numbers[i];
				umap[numbers[i]+numbers[j]+numbers[k]].nr2 = numbers[j];
				umap[numbers[i]+numbers[j]+numbers[k]].nr3 = numbers[k];
			}
	for(int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j)
			for (int k = j; k < n; ++k){
				if(umap.find(s - (numbers[i]+numbers[j]+numbers[k])) != umap.end()){
					fout << umap[s - (numbers[i]+numbers[j]+numbers[k])].nr1 << ' ' 
					<< umap[s - (numbers[i]+numbers[j]+numbers[k])].nr2 <<' ' 
					<< umap[s - (numbers[i]+numbers[j]+numbers[k])].nr3 << ' ' 
					<< numbers[i] << ' ' << numbers[j] << ' ' << numbers[k];
					return 0;
				}
	}
	fout << -1;
	return 0;
}