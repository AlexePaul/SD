#include "numberList.h"
#include <iostream>

using namespace std;

int main(){
	long long numberCount, numberMax, nr;
	cout << "Number Count = ";
	cin >> numberCount;
	cout << "\nNumber Max = ";
	cin >> numberMax;
	cout << "\nRadix Base = ";
	cin >> nr;

	numberList ob(numberCount, numberMax, nr);

	ob.radixSort();

    ob.~numberList();
    new(&ob) numberList(numberCount,numberMax, nr);

	ob.cppSort();

	ob.~numberList();
    new(&ob) numberList(numberCount, numberMax, nr);

    ob.mergeSort();

    return 0;
}