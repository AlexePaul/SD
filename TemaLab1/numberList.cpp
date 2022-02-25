#include "numberList.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

numberList::numberList(long long numberCount, long long numberMax, long long rBase):numbers(numberCount){
	this->numberCount = numberCount;
	this->radixBase = rBase;
	srand(time(NULL));
	for (long long i = 0; i < numberCount; ++i){
		this->numbers[i] = rand()%numberMax;
	}
}

void numberList::print(){
	for(long long i = 0; i < this->numberCount; ++i){
		cout << this->numbers[i] << " ";
	}
	cout << '\n';
}

long long numberList::maxDigits(){
	long long max = numbers[0];
	for(long long i = 1; i < this->numberCount; ++i){
		if(abs(numbers[i]) > max){
			max = abs(numbers[i]);
		}
	}

	long long count = 0;
	while(max){
		count++;
		max /= this->radixBase;
	}

	return count;
}

void numberList::radixSort(){
	vector<long long>bucket[this->radixBase];
	long long numOfDigits = maxDigits();
	long long power = 1;
	for (long long p = 0; p < numOfDigits; ++p){
		for(long long i = 0; i < this->numberCount; ++i){
			bucket[(this->numbers[i]/power)%this->radixBase].push_back(numbers[i]);
		}
		long long k = 0;
		for (long long i = 0; i < this->radixBase; ++i){
			for (long long j = 0; j < bucket[i].size(); ++j){
				this->numbers[k++] = bucket[i][j];
			}
			bucket[i].clear();
		}
		power *= this->radixBase;
	}
}

void numberList::checkSort(){
	for(long long i = 1; i < this->numberCount; ++i){
		if(this->numbers[i] < this->numbers[i-1]){
			cout << "The numberList isn't sorted!\n";
			return;
		}
	}
	cout << "The numberList is sorted!\n";
}