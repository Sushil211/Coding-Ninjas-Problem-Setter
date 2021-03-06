/*
    Time Complexity - O(N)
    Space Complexity - O(N)

    Where N is the total number of nodes in the tree and H is the height of the tree.
*/

#include<queue>

// Function to copy a tree.
TreeNode<int> *copyTree(TreeNode<int> *root){
    if (root == NULL){
        return NULL;
    }

    TreeNode<int> *copyRoot = new TreeNode<int>(root->data);
    copyRoot->left = copyTree(root->left);
    copyRoot->right = copyTree(root->right);
    return copyRoot;
}

void inorder(TreeNode<int>* root, TreeNode<int>* &previous) {

	if(root == NULL){
		return;
	}

	inorder(root->left, previous);
	
	previous->left = NULL;
	previous->right = root;
	previous = root;

	inorder(root->right, previous);
}

TreeNode<int> *flatten(TreeNode<int>* root) {

	if(root == NULL){
		return root;
	}

	TreeNode<int> * temp = new TreeNode<int>(-1);
	TreeNode<int> * previous = temp;

	inorder(root, previous);

	previous->left = NULL;
	previous->right = NULL;

	// Copy the tree.
	TreeNode<int> * newRoot = copyTree(temp->right);

	delete temp;
	return newRoot;
}