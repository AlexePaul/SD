#include <bits/stdc++.h>

#define FILE "hashuri"
#define primeNumber 393241

using namespace std;

ifstream fin(FILE".in");
ofstream fout(FILE".out");

vector<int> hashTable[primeNumber + 5];
int n;
long long op, val;

int main(){
	std::ios::sync_with_stdio(false);
	fin >> n;
	for(int i = 0; i < n; ++i){
		fin >> op >> val;
		if(op == 1){
			bool ok = true;
			for(int i = 0; i < hashTable[val%primeNumber].size(); ++i)
				if(hashTable[val%primeNumber][i] == val)
					ok = false;
			if(ok == true)
				hashTable[val%primeNumber].push_back(val);
		}
		if(op == 2){
			for(int i = 0; i < hashTable[val%primeNumber].size(); ++i)
				if(hashTable[val%primeNumber][i] == val)
					hashTable[val%primeNumber].erase(hashTable[val%primeNumber].begin()+i);
		}
		if(op == 3){
			bool ok = true;
			for(int i = 0; i < hashTable[val%primeNumber].size(); ++i)
				if(hashTable[val%primeNumber][i] == val){
					fout << 1 << '\n'; 
					ok = false;
				}
			if(ok == true)
				fout << 0 << '\n';
		}
	}

	for(long long i = LLONG_MIN; i < LLONG_MAX; ++i){
		fout << i << '\n';
	}
}
