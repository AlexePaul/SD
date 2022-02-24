#include "numberList.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

numberList::numberList(int numberCount, int numberMax, int rBase):numbers(numberCount){
	this->numberCount = numberCount;
	this->radixBase = rBase;
	srand(time(NULL));
	for (int i = 0; i < numberCount; ++i){
		this->numbers[i] = rand()%numberMax;
	}
}

void numberList::print(){
	for(int i = 0; i < this->numberCount; ++i){
		cout << this->numbers[i] << " ";
	}
}

int numberList::maxDigits(){
	int max = numbers[0];
	for(int i = 1; i < this->numberCount; ++i){
		if(abs(numbers[i]) > max){
			max = abs(numbers[i]);
		}
	}

	int count = 0;
	while(max){
		count++;
		max /= this->radixBase;
	}

	return count;
}

void numberList::radixSort(){
	vector<int>bucket[this->radixBase]
}