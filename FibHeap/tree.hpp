#ifndef tree_HPP
#define tree_HPP

#include <iostream>

template<typename type>
type max(type a, type b){
	return a > b ? a : b;
}

template<typename type>
struct tree{
	tree<type>* left; // this node's left brother
	tree<type>* right; // this node's right brother
	tree<type>* child; 
	type key;
	tree<type>(int x){
		left = NULL;
		right = NULL;
		child = NULL;
		key = x;
	}
	tree<type>(){
		left = NULL;
		right = NULL;
		child = NULL;
	}
	int degree(tree<type>* root){
		if(root->child == NULL)
			return 0;
		else{
			int maxim = -1;
			root = root->child;
			for(tree<type>* i = root->left; i != root && i != NULL; i = i->left){
				maxim = max (maxim, 1 + degree(i));
			}
		}
	}

};

#endif