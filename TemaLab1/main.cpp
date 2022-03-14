#include "numberList.h"
#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("test.txt");
ofstream fout("testOut.txt");

int main(){
	long long bucketNr, numberCount, numberMax, rBase, testCount, allSortTests;
	fin >> testCount;
	fin >> allSortTests;
	numberList ob;
	for(int l = 0; l < testCount; ++l){
		cout << l << '\n';
		fin >> numberCount;
		fin >> numberMax;
		fin >> rBase;
		//fin >> bucketNr;	

		if(bucketNr > numberMax)
			bucketNr = numberMax;

		fout << "Number Count = " << numberCount << '\n';
		fout << "Number Max = " << numberMax << '\n';
		fout << "Radix Base = " << rBase << '\n';
		fout << "Bucket Count = " << bucketNr << '\n';

		fout << '\n';

		ob.valueInit(numberCount, numberMax, rBase, bucketNr);
		
		if(l < allSortTests){
			ob.bucketSort();
			ob.radixSort();
		    ob.mergeSort();
		    ob.cppSort();
		    ob.shellSort();
		    ob.selectionSort();
		    ob.bucketSort();
		}
		else{
			ob.radixSort();
		}
		fout << '\n';
	}
    return 0;
}