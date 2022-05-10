#ifndef fibHeap_H
#define fibHeap_H

template<typename type>
class node<type>{
private:
	type key;
	node<type>* next;
	node<type>* prev;
public:
	node<type>(){
		this->key = 0;
		this->next = NULL;
		this->prev = NULL;
	}
	node<type>(type key){
		this->key = key;
		this->next = NULL;
		this->prev = NULL;
	}
	bool operator<(node<type> temp){
		return this->ket < temp.key;
	}
	bool operator>(node<type> temp){
		return this->ket > temp.key;
	}
};

template<typename type>
class fibHeap<type>{
private:
	node<type>* minKey;
	vector< node<type> > rootList;
public:
	void insert(type);
	fibHeap<type>(){
		this->minKey = NULL;
	}
};

#endif