#ifndef tree_HPP
#define tree_HPP

#include <iostream>

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
	tree(){
		left = NULL;
		right = NULL;
		child = NULL;
	}
};

#endif