/*
    Time Complexity: O(N). 
    Space Complexity: O(H).
    
    Where N is the total number of nodes in the tree and H is the height of the tree.
*/

#include<stack>

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
    
    // It stores the iterators for starting and ending indices
    stack<BinaryTreeNode<int> *> start, end;

    // It initialises the starting operator
    BinaryTreeNode<int> *currNode = root;

    while (currNode != NULL){
        start.push(currNode);
        currNode = currNode->left;
    }

    // It initialises the ending operator
    currNode = root;

    while (currNode != NULL){
        end.push(currNode);
        currNode = currNode->right;
    }

    // Using the two-pointer technique.
    while (start.top() != end.top()){

        // It stores the values at starting and end node data
        int val1 = start.top()->data;
        int val2 = end.top()->data;

        // If the sum of values = target, return true
        if (val1 + val2 == target)
        {
            return true;
        }

        // If the sum of values < target, then move to the next greatest closer value.
        if (val1 + val2 < target)
        {
            currNode = start.top()->right;
            start.pop();
            while (currNode != NULL)
            {
                start.push(currNode);
                currNode = currNode->left;
            }
        }

        // If the sum of values > target value, then move to the next smallest closer value .
        else
        {
            currNode = end.top()->left;
            end.pop();
            while (currNode != NULL)
            {
                end.push(currNode);
                currNode = currNode->right;
            }
        }
    }

    // If no two nodes is found, return false
    return false; 
}