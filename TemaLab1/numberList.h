#ifndef numberList_H
#define numberList_H

#include <vector>

using namespace std;

class numberList{
	vector<int> numbers;
	int numberCount;
	int radixBase;
	int maxDigits();
public:
	numberList(int numberCount, int numberMax, int rbase = 10);
	void print();
	void radixSort();
};

#endif