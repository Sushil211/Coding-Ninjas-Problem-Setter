/*
    Time Complexity: O(N). 
    Space Complexity: O(N).
    
    Where N is the total number of nodes in the tree.
*/


#include<unordered_set>

bool solve(BinaryTreeNode<int>* root, int target, unordered_set<int> &st){

    //If the root is null, we simply return false.
    if(root == NULL){
        return false;
    }

    //If the node with the value (target - root->data) is present in the set, then return true.
    if(st.find(target - root->data) != st.end()){
        return true;
    }

    //If the value is not present in the set, insert the current node data in the set.
    st.insert(root->data);

    //Call the left child and right child recursively and return true, if either of them returns true.
    return solve(root->left, target, st) || solve(root->right, target, st);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {

    //Initialize an empty unordered_set to store the values of the node.
    unordered_set<int> st;

    return solve(root, target, st);
} 