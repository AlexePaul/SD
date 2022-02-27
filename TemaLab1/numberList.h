#ifndef numberList_H
#define numberList_H

#include <vector>

using namespace std;

class numberList{
	vector<long long> numbers;
	long long numberCount;
	long long radixBase;
	int maxDigits();
	bool checkSort();
	void merge(int lf, int mid, int rt);
	void mergeSort(int lf, int rt);
public:
	numberList(long long numberCount, long long numberMax, long long rbase = 10);
	void print();
	void radixSort();
	void cppSort();
	void mergeSort();
	~numberList();
};

#endif