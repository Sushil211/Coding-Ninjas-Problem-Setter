/*
    Time Complexity:O(N). 
    Space Complexity:O(N).
    
    Where N is the total number of nodes in the tree.
*/

#include <queue>

bool isSymmetric(BinaryTreeNode<int>* root) {
	
	//If root is NULL, then simply return true.
	if(root == NULL){
		return true;
	}

	//Create a queue which will contain the nodes of the binary tree.
	queue<BinaryTreeNode<int>*> q;

	//Push the root two times to the queue initially.
	q.push(root);
	q.push(root);

	while(!q.empty()){

		//Pop two elements from the queue
		BinaryTreeNode<int>* node1 = q.front();
		q.pop();

		BinaryTreeNode<int>* node2 = q.front();
		q.pop();

		//If both the nodes are NULL, then go back to the previous step.
		if(node1 == NULL && node2 == NULL){
			continue;
		}

		//If only one of them is NULL, then simply return false. 
		if(node1 == NULL || node2 == NULL){
			return false;
		}

		//If the values of two nodes don't match, then simply return false.
		if(node1->data != node2->data){
			return false;
		}

		//Add the left child of node1, right child of node2, right child of node1 and left child of node2 to the queue in exact order.
		q.push(node1->left);
		q.push(node2->right);
		q.push(node1->right);
		q.push(node2->left);
	}

	return true;
}