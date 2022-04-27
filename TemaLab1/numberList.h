#ifndef numberList_H
#define numberList_H

#include <vector>

using namespace std;

class numberList{
	vector<long long> numbers;
	vector<long long> initialNumbers;
	vector<long long> sortedNumbers;
	long long numberCount;
	long long numberMax;
	long long radixBase;
	long long bucketCount;
	int maxDigits();
	int maxPow2();
	bool checkSort();
	void resetNumbers();
	void merge(int lf, int mid, int rt);
	void mergeSort(int lf, int rt);
public:
	void print();
	void radixSort();
	void cppSort();
	void mergeSort();
	void shellSort();
	void bucketSort();
	void selectionSort();
	void valueInit(long long numberCount, long long numberMax, long long rBase, long long bucketNr);
};

#endif