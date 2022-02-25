#ifndef numberList_H
#define numberList_H

#include <vector>

using namespace std;

class numberList{
	vector<long long> numbers;
	long long numberCount;
	long long radixBase;
	long long maxDigits();
public:
	numberList(long long numberCount, long long numberMax, long long rbase = 10);
	void print();
	void radixSort();
	void checkSort();
};

#endif