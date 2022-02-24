#ifndef numberList_H
#define numberList_H

#include <vector>

using namespace std;

class numberList{
	//int array[__MaxN];
	vector<int> v;
	int numberCount;
public:
	numberList(int numberCount, int numberMax);
	void print();
	void radixSort();
};

#endif