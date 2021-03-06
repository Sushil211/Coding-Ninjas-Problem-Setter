/*
    Time Complexity - O(N)
    Space Complexity - O(1)

    Where N is the number of nodes in the Linked List
*/

LinkedListNode<int> *reverse(LinkedListNode<int> *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    LinkedListNode<int> *prev = NULL, *curr = head, *next;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

LinkedListNode<int> *deleteGreaterOnRight(LinkedListNode<int> *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    int maximum = head->data;
    LinkedListNode<int> *p = head;
    
    while(p && p->next){

        if(p->next->data < maximum){
            LinkedListNode<int> *temp = p->next;
            p->next = p->next->next;
            delete temp;
        }

        else{
            maximum = p->next->data;
            p = p->next;
        }
    }
    
    return head;
}

LinkedListNode<int> *deleteNodes(LinkedListNode<int> * head) {

	if(head == NULL || head->next == NULL){
        return head;
    }
    
    head = reverse(head);
    head = deleteGreaterOnRight(head);
    head = reverse(head);
    
    return head;
}