   
#include <bits/stdc++.h>
using namespace std;


bool checkPreorder(int v[], int st, int dr){
	if(st >= dr)
		return true;
	int i,j;
	//impart vectorul in 2 subarbori pe care sa ii verific separat folosind divide et impera
	for(i = st+1; i <= dr; ++i) 
		if(v[i] > v[st])
			break;
	for(j = i; j <= dr; ++j)
		if(v[j] < v[st])
			return false;
	return checkPreorder(v, st+1, j-1) && checkPreorder(v, j, dr);
}

void allBstPreorders(int N) {
    int v[50];
    for(int i = 0; i < N; ++i)
    	v[i] = i+1;
    bool ok = true;
    while(ok){
    	if(checkPreorder(v,0,N-1)){
    		for(int i = 0; i < N; ++i){
    			cout << v[i] << ' ';
    		}
    		cout << '\n';
    	}
    	ok = next_permutation(v, v+N); 
    }
}
   
int main() {
    int N;
    cin >> N;
    allBstPreorders(N);
    return 0;
}
