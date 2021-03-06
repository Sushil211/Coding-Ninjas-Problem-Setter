/*
    Time Complexity - O(N * H)
    Space Complexity - O(N)

    Where N is the total number of nodes in the tree and H is the height of the tree.
*/

#include<queue>

bool search(TreeNode<int>* root, int val){
    if(root == NULL){
        return false;
    }

    if(root->data == val){
        return true;
    }

    if(root->data > val){
        return search(root->left, val);
    }

    else{
        return search(root->right, val);
    }
}

bool isDeadEnd(TreeNode<int>* root) {
    if(root == NULL){
        return false;
    }
    
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()) {
        TreeNode<int>* curr = q.front();
        q.pop();
        
        // If the current node is a leaf node.
        if(curr->left == NULL && curr->right == NULL){

        	// If curr->data = 1 and a node with data 2 is already present in the BST, then it's a dead end.
            if(curr->data == 1){
                if(search(root, 2) == true){
                    return true;
                }
            }
            else{

            	// If both the nodes having value curr->data+1 and curr->data-1 are already present in the BST, then it's a dead end.
                if((search(root, curr->data + 1) == true) && (search(root, curr->data - 1) == true)){
                    return true;
                }
            }
        }

        // If the current node is not a leaf node, then push its children to the queue.
        else{
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }

    return false;
}