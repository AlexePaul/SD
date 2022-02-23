#include "numberList.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

#define __MaxN 100000000

using namespace std;

numberList::numberList(int numberCount, int numberMax):v(numberCount){
	this->numberCount = numberCount;
	srand(time(NULL));
	for (int i = 0; i < numberCount; ++i){
		this->v[i] = rand()%numberMax;
	}
}

void numberList::print(){
	for(int i = 0; i < this->numberCount; ++i){
		cout << this->v[i] << " ";
	}
}