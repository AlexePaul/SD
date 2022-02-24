#include <iostream>

using namespace std;

int nrAparitii(int v[], int n, int s){
	int st = 0, dr = n-1, mid;
	while(st <= dr){
		mid = (st + dr) / 2;
		if(v[mid] < s){
			st = mid+1;
		}
		else if(v[mid] > s){
			dr = mid-1;
		}
		else if(v[mid] == s){
			break;
		}
	}
	int i = mid, count = 0;
	while(v[i] == s){
		count++;
		i--;
	}
	i = mid + 1;
	while(v[i] == s){
		count++;
		i++;
	}
	return count;
}

int main(){
	int n, s;
	cin >> n >> s;
	int v[100];
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	cout << nrAparitii(v, n, s);
}