#include "numberList.h"
#include <iostream>

using namespace std;

int main(){
	long long bucketNr, numberCount, numberMax, rBase;
	cout << "Number Count = ";
	cin >> numberCount;
	cout << "\nNumber Max = ";
	cin >> numberMax;
	cout << "\nRadix Base = ";
	cin >> rBase;
	cout << "\nBucket Number = ";
	cin >> bucketNr;

	numberList ob(numberCount, numberMax, rBase, bucketNr);

	ob.bucketSort();
	
	ob.~numberList();
    new(&ob) numberList(numberCount, numberMax, rBase, bucketNr);

	ob.shellSort();

	ob.~numberList();
    new(&ob) numberList(numberCount, numberMax, rBase, bucketNr);

	ob.radixSort();

    ob.~numberList();
    new(&ob) numberList(numberCount,numberMax, rBase, bucketNr);

	ob.cppSort();

	ob.~numberList();
    new(&ob) numberList(numberCount, numberMax, rBase, bucketNr);

    ob.mergeSort();

    return 0;
}