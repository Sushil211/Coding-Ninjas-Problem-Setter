/*
    Time Complexity - O(N)
    Space Complexity - O(N)

    Where N is the number of nodes in the Linked List
*/

#include<algorithm>

LinkedListNode<int> *deleteGreaterOnRight(LinkedListNode<int> *head, int *maximum){

    if(head == NULL){
        return head;
    }
    
    // Call the function recursively for head->next.
    head->next = deleteGreaterOnRight(head->next, maximum);

    // If head->data < *maximum, then there is a node having greater value on right side.
    if(head->data < *maximum){
        return head->next;
    }
    
    // Update the maximum if possible.
    *maximum = max(*maximum, head->data);
    
    return head;
}

LinkedListNode<int> *deleteNodes(LinkedListNode<int> * head) {

	if(head == NULL || head->next == NULL){
        return head;
    }
    
    int maximum = INT_MIN;
    return deleteGreaterOnRight(head, &maximum);
}