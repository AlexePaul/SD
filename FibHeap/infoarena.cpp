#include <fstream>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

template<typename type>
struct tree{
	tree<type>* left; // this node's left brother
	tree<type>* right; // this node's right brother
	tree<type>* child; 
	type key;
	tree<type>(int x){
		left = this;
		right = this;
		child = NULL;
		key = x;
	}
	tree<type>(){
		left = this;
		right = this;
		child = NULL;
	}
	int degree(tree<type>* root){
		if(root == NULL || root->child == NULL)
			return 0;
		else{
			int maxim = -1;
			tree<type>* i = root->child;
			do{
				maxim = max (maxim, 1 + degree(i));
				i = i->left;
			}while(i != NULL && i != root);
			return maxim;
		}
	}

};

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
	fibHeap(fibHeap<type> *fH): root(){
		this->root = fH->root;
	}
	fibHeap(tree<type>* temp){
		root = temp;
	}
	void insert(type key);
	void insert(tree<type>* temp);
	void merge(fibHeap<type> fH);
	void repair();
	void empty();
	friend ostream& operator << <>(ostream&, fibHeap<type>&);
	type getMax();
	type removeMax();
private:
	tree<type>* root;
};

/*
	The way that this function is implemented, it will always insert to the left of the root 
	unless the node we want inserted is bigger than the root, if that's the case it will be inserted to the right of it.
	This way it's easier to keep the list circular.
*/

template<typename type>
void fibHeap<type>::insert(type key){
	if(root == NULL)
		root = new tree<type>(key);
	else if(root->key > key){ // in case there's only 1 node in the rootList, i make sure to keep it circular. 
		if(root->left == NULL){
			root->left = new tree<type>(key);
			root->left->left = root;
			root->right = root->left;
		}
		else{ // if the key that we want inserted is smaller, we can just insert it to the left of the root.
			tree<type>* temp = new tree<type>(key);
			temp->right = root;
			temp->left = root->left;
			root->left = temp;
		}
	}
	else if(root->key <= key){
		if(root->left == NULL){ // in case there's only 1 node in the rootList, i make sure to keep it circular.
			tree<type>* temp = new tree<type>(key);
			temp->left = root;
			temp->right = root;
			root->left = temp;
			root->right = temp;
			root = temp;
		}
		else{ // if the key is bigger than the root, we have to insert it to the right of the root
			tree<type>* temp = new tree<type>(key);
			temp->right = root->right;
			temp->left = root;
			root->right->left = temp;
			root->right = temp;
			root = temp;
		}
	}
}

template<typename type>
void fibHeap<type>::insert(tree<type>* temp){ // used to insert a whole tree, same principles as the one inserting a single key
	if(root == NULL){
		root = temp;
		return;
	}
	else if(root->key > temp->key){ // in case there's only 1 node in the rootList, i make sure to keep it circular. 
		if(root->left == NULL){
			root->left = temp;
			temp->left = root;
			root->right = root->left;
		}
		else{ // if the key that we want inserted is smaller, we can just insert it to the left of the root.
			temp->right = root;
			temp->left = root->left;
			root->left = temp;
		}
	}
	else if(root->key <= temp->key){
		if(root->left == NULL){ // in case there's only 1 node in the rootList, i make sure to keep it circular.
			temp->left = root;
			temp->right = root;
			root->left = temp;
			root->right = temp;
			root = temp;
		}
		else{ // if the key is bigger than the root, we have to insert it to the right of the root
			temp->right = root->right;
			temp->left = root;
			root->right->left = temp;
			root->right = temp;
			root = temp;
		}
	}
}

template<typename type>
void print(ostream& o, tree<type>* root){
	if(root == NULL)
		return;
	tree<type>* i = root;
	do{
		o << i->key << ' ';
		print(o, i->child);
		i = i->left;
	}while(i != NULL && i != root);
	o << '\n';
}

template<typename type>
void fibHeap<type>::repair(){
	tree<type>* i = root;
	do{
		tree<type>* j = root;
		do{ assert(i != NULL);
			assert(j != NULL);
			if(i != j && i->degree(i) == j->degree(j) && i->key > j->key){
				fibHeap<type>* temp = new fibHeap<type>(i->child);
				j->left->right = j->right;
				j->right->left = j->left;
				j->right = NULL;
				j->left = NULL;
				temp->insert(j);
				i->child = temp->root;
				break;
			}
			j = j->left;
		}while(j != NULL && j != root);
		i = i->left;
	}while(i != NULL && i != root);
}

template<typename type>
ostream& operator << (ostream& o, fibHeap<type>& heap){
	print(o, heap.root);
	o << '\n';
	return o;
}

template<typename type>
type fibHeap<type>::getMax(){
	if(root == NULL)
		return 0; // the max key of an empty heap will be 0
	else{
		return root->key;
	}
}

template<typename type>
type fibHeap<type>::removeMax(){
	if(root == NULL)
		return 0; // the max key of an empty heap will be 0
	else{
		type temp = root->key;
		tree<type>* i = root->child;
		do{
			if(i == NULL)
				break;
			this->insert(i);
			i = i->left;
		}while(i != NULL && i != root->child);
		if(root->left != root && root->left != root->right){
			root->right->left = root->left;
			root->left->right = root->right;
			root = root->left;
			i = root;
			cout << *this << '\n';
			do{
				if(i->key > root->key){
					swap(i, root);
				}
				i = i->left;
			}while(i != NULL && i != root);
		}
		else if(root->left == root){
			this->root = NULL;
		}
		if(root != NULL)
			repair();
		//cout << *this << '\n';
		return temp;
	}

}

template<typename type>
void fibHeap<type>::empty(){
	this->root = NULL;
}

template<typename type>
void fibHeap<type>::merge(fibHeap<type> fH){
	if(this->root->key > fH.root->key){
		tree<type>* temp = fH.root;
		if(temp->right != NULL && temp->left != NULL){
			temp->right->left = root->left;
			root->left->right = temp->right;
			root->left = temp;
			temp->right = root;
		}
		else{
			this->insert(temp->key);
		}
	}
	else{
		tree<type>* temp = fH.root;
		if(temp->right != NULL && temp->left != NULL){
			root->right->left = temp->left;
			temp->left->right = root->right;
			temp->left = root;
			root->right = temp;
			root = temp;
		}
		else{
			this->insert(temp->key);
		}
	}
}
ifstream fin("mergeheap.in");
ofstream fout("mergeheap.out");

int main(){
	int n, q, op, m, a, b, x;
	vector< fibHeap<int> > heaps;
	fin >> n >> q;
	heaps.resize(n+5);
	for(int i = 0; i < q; ++i){
		fin >> op;
		if(op == 1){
			fin >> m >> x;
			heaps[m].insert(x);
			continue;
		}
		if(op == 2){
			fin >> m;
			fout << heaps[m].removeMax() << '\n';
			continue;
		}
		if(op == 3){
			fin >> a >> b;
			heaps[a].merge(heaps[b]);
			heaps[b].empty();
		}
	}
}