#include "numberList.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <sys/time.h>

using namespace std;

numberList::numberList(long long numberCount, long long numberMax, long long rBase):numbers(numberCount){
	this->numberCount = numberCount;
	this->radixBase = rBase;
	srand(time(NULL));
	for (int i = 0; i < numberCount; ++i){
		this->numbers[i] = rand()%numberMax;
	}
}

numberList::~numberList(){
	this->numbers.clear();
}

void numberList::print(){
	for(int i = 0; i < this->numberCount; ++i){
		cout << this->numbers[i] << " ";
	}
	cout << '\n';
}

int numberList::maxDigits(){
	long long max = numbers[0];
	for(int i = 1; i < this->numberCount; ++i){
		if(abs(numbers[i]) > max){
			max = abs(numbers[i]);
		}
	}

	long long count = 0;
	while(max){
		count++;
		max = max >> this->radixBase;
	}

	return count;
}

void numberList::radixSort(){
	struct timeval begin, end;
	gettimeofday(&begin, 0);
	vector<long long>bucket[1 << this->radixBase];
	long long numOfDigits = maxDigits();
	long long power = 0;
	for (int p = 0; p < numOfDigits; ++p){
		for(int i = 0; i < this->numberCount; ++i){
			bucket[(this->numbers[i]>>power)%(1 << this->radixBase)].push_back(this->numbers[i]);
		}
		long long k = 0;
		for (int i = 0; i < (1 <<this->radixBase); ++i){
			for (int j = 0; j < bucket[i].size(); ++j){
				this->numbers[k++] = bucket[i][j];
			}
			bucket[i].clear();
		}
		power += this->radixBase;
	}
	gettimeofday(&end, 0);
	long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    if(this->checkSort() == true)
   		cout << "RadixSort: " << elapsed << '\n'; 
}

bool numberList::checkSort(){
	for(int i = 1; i < this->numberCount; ++i){
		if(this->numbers[i] < this->numbers[i-1]){
			cout << "The numberList isn't sorted!\n";
			cout << this->numbers[i] << ' ' << this->numbers[i-1];
			return false;
		}
	}
	return true;
}

void numberList::cppSort(){
	struct timeval begin, end;
	gettimeofday(&begin, 0);
	sort(this->numbers.begin(), this->numbers.end());
	gettimeofday(&end, 0);
	long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    if(this->checkSort() == true)
   		cout << "Cpp-Sort: " << elapsed << '\n'; 

}

void numberList::merge(int lf, int mid, int rt){
	long long lenOfLfVector = mid - lf + 1;
	long long lenOfRtVector = rt - mid;
	vector<long long>lfVector(lenOfLfVector);
	vector<long long>rtVector(lenOfRtVector);

	for(int i = 0; i < lenOfLfVector; i++)
        lfVector[i] = this->numbers[lf + i];
    for(int i = 0; i < lenOfRtVector; i++)
        rtVector[i] = this->numbers[mid + 1 + i];
    int i = 0, j = 0;
    int mergeIndex = lf;

    while(i < lenOfLfVector && j < lenOfRtVector){
    	if(lfVector[i] < rtVector[j]){
    		this->numbers[mergeIndex] = lfVector[i];
    		mergeIndex++;
    		i++;
    	}
    	else{
    		this->numbers[mergeIndex] = rtVector[j];
    		mergeIndex++;
    		j++;
    	}
    }

    while(i < lenOfLfVector){
    	this->numbers[mergeIndex] = lfVector[i];
    	mergeIndex++;
    	i++;
    }

    while(j < lenOfRtVector){
    	this->numbers[mergeIndex] = rtVector[j];
    	mergeIndex++;
    	j++;
    }
}

void numberList::mergeSort(int lf, int rt){
	long long mid = (lf+rt)/2;

	if(lf >= rt)
		return;

	mergeSort(lf, mid);
	mergeSort(mid+1, rt);
	merge(lf, mid, rt);
}

void numberList::mergeSort(){
	struct timeval begin, end;
	gettimeofday(&begin, 0);

	mergeSort(0, this->numberCount);

	gettimeofday(&end, 0);
	long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    if(this->checkSort() == true)
   		cout << "MergeSort: " << elapsed << '\n';
}