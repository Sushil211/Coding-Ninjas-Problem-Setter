/*
    Time Complexity: O(N*H). 
    Space Complexity: O(N).
    
    Where N is the total number of nodes in the tree and H is the height of the tree.
*/


#include<queue>

bool search(BinaryTreeNode<int>* root, int key){

    // Base case
    if (root == NULL){
        return false;
    }

    return ((root->data == key) || 
        (root->data < key) && search(root->right, key) || 
        (root->data > key) && search(root->left, key));
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {

    queue<BinaryTreeNode<int>*> q;

    //Push the root to the queue
    q.push(root);
    
    while(!q.empty()){

        //Pop the first element from the queue.
        BinaryTreeNode<int>* curr = q.front();
        q.pop();
        
        //If the value of the current node is not exactly half of the target value, then search for the node with value (target - curr->val)
        if(curr->data * 2 != target){

            if(search(root, target - curr->data) == true){
                return true;
            }
        }
        
        //Push the left and the right child of the current node to the queue if they are not null.
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
    }
        
    //Finally return false.
    return false;
} 