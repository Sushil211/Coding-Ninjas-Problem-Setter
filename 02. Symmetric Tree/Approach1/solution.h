/*
    Time Complexity:O(N). 
    Space Complexity:O(N).
    
    Where N is the total number of nodes in the tree.
*/

bool isMirrorReflection(BinaryTreeNode<int>* node1, BinaryTreeNode<int>* node2){

	//If both the nodes are NULL, then simply return true.
	if(node1 == NULL && node2 == NULL){
		return true;
	}

	//If only one of them is NULL, then simply return false. 
	if(node1 == NULL || node2 == NULL){
		return false;
	}

	//Return true if the following three condition holds:
	/*
		1. Two nodes must have the same value.
		2. The left subtree of the left tree and right subtree of the right tree must be a mirror reflection of each other.
		3. The right subtree of the left tree and left subtree of the right tree must be a mirror reflection of each other.
	*/

	return (node1->data == node2->data) 
	&& isMirrorReflection(node1->left, node2->right) 
	&& isMirrorReflection(node1->right, node2->left);
}

bool isSymmetric(BinaryTreeNode<int>* root) {

	//If root is NULL, then simply return true.
	if(root == NULL){
		return true;
	}

	//Check whether the left subtree and the right subtree of the root are mirror image of each other or not.
	return isMirrorReflection(root->left, root->right);
}