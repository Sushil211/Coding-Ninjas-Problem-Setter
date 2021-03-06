/*
    Time Complexity - O(1)
    Space Complexity - O(1)
*/

void deleteNode(LinkedListNode<int> * node) {
    // Write your code here

	//Create a temp pointer that initially points to node->next.
    LinkedListNode<int> * temp = node->next;

    //Store the data of temp as node->data and make node->next = temp->next.
    node->data = temp->data;
    node->next = temp->next;

    //Finally delete the temp pointer.
    delete temp;
}