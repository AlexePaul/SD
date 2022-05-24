#include "fibHeap.h"
#include "tree.hpp"

using namespace std;

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
	if(root == NULL)
		root = temp;
	else if(root->key > temp->key){ // in case there's only 1 node in the rootList, i make sure to keep it circular. 
		if(root->left == NULL){
			root->left = temp;
			root->left->left = root;
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
	for(tree<type>* i = root; i->left != root && i != NULL; i = i->left){
		o << i->key << ' ';
		print(o, i->child);
	}
}

template<typename type>
void fibHeap<type>::repair(){
	for(tree<type>* i = root; i->left != root && i != NULL; i = i->left){
		tree<type>* j = root;
		while(j->left != root){
			if(i->degree(i) == j->degree(j) && i != j){
				fibHeap<type>* temp = new fibHeap<type>(i->child);
				temp->merge(*(new fibHeap<type>(j)));
				j->left->right = j->right;
				j->right->left = j->left;
				break;
			}
			j = j->left;
		}
	}
}

template<typename type>
ostream& operator << (ostream& o, fibHeap<type>& heap){
	print(o, heap.root);
	o << '\n';

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