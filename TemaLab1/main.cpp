#include "numberList.h"
#include <iostream>

using namespace std;

int main(){
	int maxNumbers, maxSize;
	cin >> maxNumbers >> maxSize;
	numberList ob(maxNumbers, maxSize);
	ob.print();
}