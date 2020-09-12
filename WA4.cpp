#include <iostream>
#include "node.h"

using namespace std;

int height(Node *);
Node* rotate_right(Node* old_root);
Node* rotate_left(Node* old_root);

void insert(Node*& root, int data)
{

   if (root == nullptr)
      root =  new Node(data);

   else if (data < root->data)
      insert(root->left, data);
  
   else if(data >root->data)
      insert(root->right, data);
	
   int leftHeight = height(root->left);
   int rightHeight = height(root->right);

   root->ht = max(leftHeight,rightHeight) + 1; 
 
 if( ( leftHeight - rightHeight) > 1 && data < root->left->data)	
	{
	root =  rotate_right(root);
	}

    if( (leftHeight - rightHeight) < -1 && data > root->right->data)
	root = rotate_left(root);
	
   if( (leftHeight - rightHeight) > 1 && data > root->left->data)
	{
		root->left = rotate_left(root->left);
		root =  rotate_right(root);
	}

    if( (leftHeight - rightHeight) < -1 && data < root->right->data)
	{
		root->right = rotate_right(root -> right);
		root = rotate_left(root);
	} 

}

int height(Node *node)
{
   if (!node) return -1;
   return node->ht;
}


Node* rotate_left(Node* old_root)
{
Node *new_root = old_root->right;
old_root->right = new_root->left;
new_root->left = old_root;
old_root->ht = max(height(old_root->left),height(old_root->right)) + 1;
new_root->ht = max(height(new_root->left),height(new_root->right)) + 1;
return new_root;
}

Node* rotate_right(Node* old_root)
{
Node* new_root = old_root->left;
old_root->left = new_root->right;
new_root->right = old_root;
old_root->ht = max(height(old_root->right),height(old_root->left)) + 1;
new_root->ht = max(height(new_root->right),height(new_root->left)) + 1;
return new_root;
}

/*
Node* rotate_right(Node* old_root)
{
	Node* new_root = old_root->left;
	Node* temp = new_root->right;

	new_root->right = old_root;
	old_root->left = temp;
	
	old_root->ht =max(height(old_root->right),height(old_root->left)) + 1;
	new_root->ht = max(height(new_root->right),height(new_root->left)) + 1;
	
	return new_root;
}

Node* rotate_left(Node* old_root)
{
	Node* new_root = old_root->right;
	Node *temp = new_root->left;

	new_root->right = temp;
	old_root->left = new_root;

	old_root->ht = max(height(old_root->left),height(old_root->right)) + 1;
	new_root->ht = max(height(new_root->left),height(new_root->right)) + 1;

	return new_root;
}
*/



