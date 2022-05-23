#include <iostream>
#include "fibHeap.h"
#include "fibHeap.cpp"

using namespace std;

fibHeap<int> heap;
fibHeap<int> heap2;

int main(){
	heap.insert(5);
	heap.insert(10);
	heap2.insert(14);
	heap2.insert(15);
	heap2.insert(16);
	heap2.merge(heap);
	cout << heap2;
}