#include "numberList.h"
#include <iostream>

using namespace std;

int main(){
	int maxNumbers, maxSize;
	cout << "Max Number = ";
	cin >> maxNumbers;
	cout << "\nMax Size = ";
	cin >> maxSize;
	numberList ob(maxSize,maxNumbers);
	ob.print();
	ob.radixSort();
}