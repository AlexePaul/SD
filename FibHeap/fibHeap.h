#ifndef fibHeap_H
#define fibHeap_H

#include "tree.hpp"
using namespace std;


// this Heap implementation will be the implementation of a max-Heap

template<class T>
class fibHeap;

template<typename type>
ostream& operator <<(ostream& o, fibHeap<type>& heap);

template<typename type>
class fibHeap{
public:
	fibHeap(): root(){
		root = NULL;
	}
	fibHeap(const fibHeap<type> &fH): root(){
		this->root = fH.root;
	}
	void insert(type key);
	void insert(tree<type>* temp);
	void merge(fibHeap<type> fH);
	friend ostream& operator << <>(ostream&, fibHeap<type>&);
	type getMax();
private:
	tree<type>* root;
};

#endif