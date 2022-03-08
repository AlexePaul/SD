#ifndef numberList_H
#define numberList_H

#include <vector>

using namespace std;

class numberList{
	vector<long long> numbers;
	long long numberCount;
	long long numberMax;
	long long radixBase;
	long long bucketCount;
	int maxDigits();
	int maxPow2();
	bool checkSort();
	void merge(int lf, int mid, int rt);
	void mergeSort(int lf, int rt);
public:
	numberList(long long numberCount, long long numberMax, long long rBase = 10, long long bucketNr = 1000);
	void print();
	void radixSort();
	void cppSort();
	void mergeSort();
	void shellSort();
	void bucketSort();
	~numberList();
};

#endif