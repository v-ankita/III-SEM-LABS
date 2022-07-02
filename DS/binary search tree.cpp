#include<iostream>
using namespace std;

struct node
{
	int val;
	node *left;
	node *right;
};

node* getNewNode(int x){
	node *temp = new node;
	temp->val = x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

node* rootNode =NULL;

node* insert(node* root, int x){
	if(root == NULL){
		node *temp = getNewNode(x);
		return temp;
	}
	if( x < root->val){
		root->left = insert(root->left , x);
	}
	else if( x > root->val){
		root->right = insert(root->right , x);
	}
}
