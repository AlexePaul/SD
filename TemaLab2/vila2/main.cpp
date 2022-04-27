#include <deque>
#include <fstream>
#define FILE "vila2"

using namespace std;

ifstream fin(FILE".in");
ofstream fout(FILE".out");

deque< pair<int,int> > dmax;
deque< pair<int,int> > dmin;
int n, k, x;
int maxdif = -1;

int main(){
	fin >> n >> k;
	for(int i = 0; i < n; ++i){
		fin >> x;
		while(dmax.size() > 0 && i - dmax.front().second > k){
			dmax.pop_front();
		}
		while(dmin.size() > 0 && i - dmin.front().second > k){
			dmin.pop_front();
		}
		while(dmax.size() > 0 && x >= dmax.back().first){
			dmax.pop_back();
		}
		dmax.push_back({x,i});
		while(dmin.size() > 0 && x <= dmin.back().first){
			dmin.pop_back();
		}
		dmin.push_back({x,i});
		if(dmax.front().first - dmin.front().first > maxdif){
			maxdif = dmax.front().first - dmin.front().first;
		}
	}
	fout << maxdif;
}