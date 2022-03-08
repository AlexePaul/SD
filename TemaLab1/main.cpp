#include "numberList.h"
#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("test.txt");

int main(){
	long long bucketNr, numberCount, numberMax, rBase, testCount;
	fin >> testCount;
	numberList ob;
	for(int l = 0; l < testCount; ++l){
		fin >> numberCount;
		fin >> numberMax;
		fin >> rBase;
		fin >> bucketNr;

		ob.valueInit(numberCount, numberMax, rBase, bucketNr);

		ob.bucketSort();
		ob.radixSort();
	    ob.mergeSort();
	    ob.cppSort();
	    ob.shellSort();
	    ob.selectionSort();
	}
    return 0;
}