#include <fstream>
#include <deque>
#define FILE "alibaba"

using namespace std;

ifstream fin(FILE".in");
ofstream fout(FILE".out");

int n,k;
char c;
deque<int> q; 

int main(){
	fin >> n >> k;
	for(int i = 0; i < n; ++i){
		fin >> c;
		while(!q.empty() && (int)c-48 > q.back() && q.size()+(n-i) > n-k)
			q.pop_back();
		q.push_back((int)c-48);
	}
	for(int i = 0; i < n-k; ++i){
		fout << q.front();
		q.pop_front();
	}
}