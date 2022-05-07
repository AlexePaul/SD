#include <bits/stdc++.h>
#define FILE "zeap"

using namespace std;

ifstream fin(FILE".in");
ofstream fout(FILE".out");

class BST{	
	int value;
	int size;
	BST* left;
	BST* right;
public:
	BST* insertion(BST*,int);
	void insert(int);
	int remove(int);
	BST* findSuccessor(BST*);
	BST* delNode(BST*, int);
	void inorder(BST* root);
	bool find(int);
	bool search(BST*, int);
	int maxDif();
	int minDif();
	BST();
	BST(int);
};

BST* BST::insertion(BST* root,int value){
	if(!root){
		return new BST(value);
	}
	else{
		if(value < root->value){
			root->left = insertion(root->left, value);
		}
		else{
			root->right = insertion(root->right, value);
		}
	}
	return root;
}

void BST::insert(int value){
	if(this->size != 0){
		insertion(this, value);
		this->size++;
	}
	else{
		this->value = value;
		this->size++;
	}
}

int ant = INT_MAX,minDifv;

void BST::inorder(BST* root){
	if (!root) {
        return;
    }
    inorder(root->left);
    if(fabs(root->value - ant) < minDifv)
    	minDifv = fabs(root->value - ant);
    ant = root->value;
    inorder(root->right);
}

int BST::remove(int value){
	this->size--;
	if(search(this,value) == 1)
		delNode(this,value);
	else
		return -1;
	return 1;
}

BST* BST::findSuccessor(BST* root){
	BST* temp = root;
	while(temp && temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

BST* BST::delNode(BST* root, int value){
	if(root == NULL)
		return root;
	if(value < root->value){
		root->left = delNode(root->left, value);
	}
	else if(value > root->value){
		root->right = delNode(root->right, value);
	}
	else if(value == root->value){
		if(root->left == NULL && root->right == NULL){
			delete root;
			return NULL;
		}
		if(root->left == NULL){
			BST* temp = root->right;
			delete root;
			return temp;
		}
		if(root->right == NULL){
			BST* temp = root->left;
			delete root;
			return temp;
		}

		BST* successor = findSuccessor(root->right);

		root->value = successor->value;

		root->right = delNode(root->right, successor->value);
	}
	return root;
}

bool BST::find(int value){
	return search(this, value);
}

bool BST::search(BST* root, int value)
{
	if(root == NULL)
		return 0;
    if (root->value == value)
       return 1;
    if (root->value < value)
       return search(root->right, value);
 	return search(root->left, value);
}

int BST::maxDif(){
	if(size < 1)
		return -1;
	BST* smallest = this;
	BST* biggest = this;
	while(smallest && smallest->left != NULL){
		smallest = smallest->left;
	}
	while(biggest && biggest->right != NULL){
		biggest = biggest->right;
	}
	return biggest->value - smallest->value;
}

/*
	1
	 \
	  7
*/
BST::BST(){
	this->value = 0;
	this->size = 0;
	this->left = NULL;
	this->right = NULL;
}

BST::BST(int value){
	this->value = value;
	this->left = NULL;
	this->right = NULL;
}

int BST::minDif(){
	if(size < 1)
		return -1;
	ant = INT_MAX;
	minDifv = INT_MAX;
	inorder(this);
	return minDifv;
}

int main(){
	char c;
	int x;
	BST tree;
	while(fin >> c){
		if(c == 'I'){
			fin >> x;
			tree.insert(x);
		}
		if(c == 'S'){
			fin >> x;
			if(tree.remove(x) == -1)
			fout << -1 << '\n';
		}
		if(c == 'C'){
			fin >> x;
			fout << tree.find(x) << '\n';
		}
		if(c == 'M'){
			fin >> c;
			fin >> c;
			if(c == 'N'){
				fout << tree.minDif() << '\n';
			}
			if(c == 'X'){
				fout << tree.maxDif() << '\n';
			}
		}
	}
}