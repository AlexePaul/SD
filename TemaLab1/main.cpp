#include "numberList.h"
#include <iostream>

using namespace std;

int main(){
	long long maxNumbers, maxSize;
	cout << "Max Number = ";
	cin >> maxNumbers;
	cout << "\nMax Size = ";
	cin >> maxSize;
	int nr = 1 << 16;
	numberList ob(maxSize,maxNumbers, nr);
	ob.radixSort();
	ob.checkSort();
}