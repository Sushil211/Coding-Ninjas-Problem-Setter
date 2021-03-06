/*
    Time Complexity: O(N). 
    Space Complexity: O(N).
    
    Where N is the total number of nodes in the tree.
*/

#include<vector>

void inorder(BinaryTreeNode<int>* root, vector<int> &inorderArray){

    // Base Case
    if(root == NULL){
        return;
    }
    
    inorder(root->left,inorderArray);
    inorderArray.push_back(root->data);
    inorder(root->right,inorderArray);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
    
    vector<int> inorderArray;

    //This inorder function stores the value of nodes in the vector inorderArray in the inorder traversal.
    inorder(root, inorderArray);

    //Keep two pointers i and j at the beginning and at the end of the array respectively.
    int i=0,j=inorderArray.size()-1;
        
    while(i < j)
    {
        int sum = inorderArray[i] + inorderArray[j];

        //If the sum is equal to the target value, then return true.
        if(sum == target){
            return true;
        }
        
        //If the sum exceeds the target value, then decrement j by 1. 
        if(sum > target){
            j--;
        }

        //If the sum is less than the target value, then increment i by 1.
        else{
            i++;
        }
    }

    //Finally, return false.
    return false;
}