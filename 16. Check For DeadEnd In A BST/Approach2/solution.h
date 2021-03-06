/*
    Time Complexity - O(N)
    Space Complexity - O(N)

    Where N is the total number of nodes in the given BST.
*/

#include<unordered_set>
#include<queue>

bool isDeadEnd(TreeNode<int>* root) {
    if(root == NULL){
        return false;
    }
    
    unordered_set<int> all, leaves;
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()){

        TreeNode<int>* curr = q.front();
        q.pop();

        // Insert the data of all the nodes to the "all" set.
        all.insert(curr->data);
        
        // If the current node is a leaf node, then insert the data to the "leaves" set.
        if(curr->left == NULL && curr->right == NULL){
            leaves.insert(curr->data);
        }

        // If the current node is not a leaf node, then push its children to the queue.
        else{
            if(curr->left){
                q.push(curr->left);
            }if(curr->right){
                q.push(curr->right);
            }
        }
    }
    
    for(int data: leaves){
        if(data == 1 && all.find(2) != all.end()){
            return true;
        }
        else if(all.find(data+1) != all.end() && all.find(data-1) != all.end()){
            return true;
        }
    }
    
    return false;
}