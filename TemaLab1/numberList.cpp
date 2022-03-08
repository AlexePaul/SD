#include "numberList.h"

#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <sys/time.h>

using namespace std;

ofstream fout("test-out.txt");

void numberList::valueInit(long long numberCount, long long numberMax, long long rBase, long long bucketNr){
	this->numberCount = numberCount;
	this->numberMax = numberMax;
	this->radixBase = rBase;
	this->bucketCount = bucketNr;
	numbers.resize(this->numberCount);
	initialNumbers.resize(this->numberCount);
	srand(time(NULL));
	for (int i = 0; i < numberCount; ++i){
		this->initialNumbers[i] = rand()%numberMax;
		this->numbers[i] = this->initialNumbers[i];
	}
}

void numberList::resetNumbers(){
	for(int i = 0; i < this->numberCount; ++i){
		this->numbers[i] = this->initialNumbers[i];
	}
}

void numberList::print(){
	for(int i = 0; i < this->numberCount; ++i){
		fout << this->numbers[i] << " ";
	}
	fout << '\n';
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
    long double elapsed = seconds + microseconds*1e-6;
    fout << "RadixSort: ";
    if(this->checkSort() == true)
   		fout << elapsed << '\n'; 
}

bool numberList::checkSort(){
	for(int i = 1; i < this->numberCount; ++i){
		if(this->numbers[i] < this->numbers[i-1]){
			fout << "The numberList isn't sorted!\n";
			this->resetNumbers();
			return false;
		}
	}
	this->resetNumbers();
	return true;
}

void numberList::cppSort(){
	struct timeval begin, end;
	gettimeofday(&begin, 0);
	sort(this->numbers.begin(), this->numbers.end());
	gettimeofday(&end, 0);
	long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    long double elapsed = seconds + microseconds*1e-6;
    fout << "CppSort: ";
    if(this->checkSort() == true)
   		fout << elapsed << '\n'; 

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
    long double elapsed = seconds + microseconds*1e-6;
    fout << "MergeSort: ";
    if(this->checkSort() == true)
   		fout << elapsed << '\n';
}

int numberList::maxPow2(){
	int n = this->numberCount;
	int kcount = 0;
	while(n != 1){
		kcount++;
		n = n >> 1;
	}
	return 1 << kcount;
}

void numberList::shellSort(){
	struct timeval begin, end;
	gettimeofday(&begin, 0);

	for(int gap = maxPow2(); gap > 0; gap = gap >> 1){
		for(int i = gap; i < this->numberCount; ++i){
			long long aux = this->numbers[i];
			int j;
			for(j = i; j >= gap && this->numbers[j - gap] > aux; j -= gap)
				this->numbers[j] = this->numbers[j - gap];
			this->numbers[j] = aux;
		}
	}

	gettimeofday(&end, 0);
	long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    long double elapsed = seconds + microseconds*1e-6;
    fout << "ShellSort: ";
    if(this->checkSort() == true)
   		fout << elapsed << '\n';
}

void numberList::bucketSort(){
	vector<int>bucket[this->bucketCount+1];
	struct timeval begin, end;
	gettimeofday(&begin, 0);

	for(int i = 0; i < this->numberCount; ++i){
		bool ins = 0;
		long long bucketToInsertIn = this->numbers[i]/(this->numberMax/this->bucketCount);
		for(int j = 0; j+1 < bucket[bucketToInsertIn].size(); ++j){
			if(bucket[bucketToInsertIn][j] <= this->numbers[i] && this->numbers[i] < bucket[bucketToInsertIn][j+1]){
				bucket[bucketToInsertIn].insert(bucket[bucketToInsertIn].begin() + j + 1,this->numbers[i]);
				ins = 1;
				break;
			}
		}
		if(bucket[bucketToInsertIn].size() == 0){
			bucket[bucketToInsertIn].insert(bucket[bucketToInsertIn].begin(),this->numbers[i]);
			continue;
		}
		if(ins == 0 && bucket[bucketToInsertIn].size() > 0){
			if(bucket[bucketToInsertIn][0] >= this->numbers[i])
				bucket[bucketToInsertIn].insert(bucket[bucketToInsertIn].begin(),this->numbers[i]);
			if(bucket[bucketToInsertIn][0] < this->numbers[i])
				bucket[bucketToInsertIn].insert(bucket[bucketToInsertIn].end(),this->numbers[i]);
			
		}
	}

	int k = 0;
	for(int i = 0; i < this->bucketCount; ++i){
		for(int j = 0; j < bucket[i].size(); ++j){
			this->numbers[k++] = bucket[i][j];
		}
	}

	gettimeofday(&end, 0);
	long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    long double elapsed = seconds + microseconds*1e-6;
    fout << "BucketSort: ";
    if(this->checkSort() == true)
   		fout << elapsed << '\n';
}
void numberList::selectionSort(){
	struct timeval begin, end;
	gettimeofday(&begin, 0);

	for(int i = 0; i < this->numberCount; ++i){
		for(int j = 0; j < this->numberCount; ++j){
			if(this->numbers[i] < this->numbers[j])
				swap(this->numbers[i], this->numbers[j]);
		}
	}

	gettimeofday(&end, 0);
	long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    long double elapsed = seconds + microseconds*1e-6;
    fout << "SelectionSort: ";
    if(this->checkSort() == true)
   		fout << elapsed << '\n';
}