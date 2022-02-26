#include "numberList.h"
#include <iostream>

using namespace std;

int main(){
	long long maxNumbers, maxSize, nr;
	cout << "Max Number = ";
	cin >> maxNumbers;
	cout << "\nMax Size = ";
	cin >> maxSize;
	cout << "\nRadix Base = ";
	cin >> nr;
	numberList ob(maxSize,maxNumbers, nr);

	ob.radixSort();

    ob.~numberList();
    new(&ob) numberList(maxSize,maxNumbers, nr);

	ob.cppSort();
}