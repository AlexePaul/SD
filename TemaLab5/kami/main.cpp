#include <bits/stdc++.h>
#define FILE "kami"

using namespace std;

ifstream fin(FILE".in");
ofstream fout(FILE".out");

int N,M,op,x,y;
int arr[100005];
int maxim = INT_MIN;

int main(){
	ios::sync_with_stdio(false);
	
	fin >> N;
	for(int i = 1; i <= N; ++i){
		fin >> arr[i];
		if(maxim < arr[i])
			maxim = arr[i];
	}

	fin >> M;
	for(int i = 1; i <= M; ++i){
		fin >> op;
		if(op == 0){
			fin >> x >> y;
			arr[x] = y;
			if(maxim < y)
			maxim = y;
		}
		if(op == 1){
			fin >> x;
			int sum = arr[x];
			bool found = false;
			for(int i = x-1; i >= 1; i--){
				if(sum <= arr[i]){
					fout << i << '\n';
					found = true;
					break;
				}
				if(sum > maxim){
					fout << 0 << '\n';
					found = true;
					break;
				}
				sum += arr[i];
			}
			if(found == false)
				fout << 0 << '\n';

		}
	}
}