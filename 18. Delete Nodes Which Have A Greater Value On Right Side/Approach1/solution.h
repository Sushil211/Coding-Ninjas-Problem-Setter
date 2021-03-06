/*
    Time Complexity - O(N ^ 2)
    Space Complexity - O(1)

    Where N is the number of nodes in the Linked List
*/

LinkedListNode<int> *deleteNodes(LinkedListNode<int> * head) {

    if(head == NULL || head->next == NULL){
        return head;
    }
    
    LinkedListNode<int> *p = head, *newHead = NULL, *prev;

    while(p){
        LinkedListNode<int> *temp = p;
        LinkedListNode<int> *q = p->next;
        bool isGreaterOnRight = false;
        
        while(q){
            if(q->data > p->data){

                if(newHead){
                    prev->next = p->next;
                }

                p = p->next;
                delete temp;
                isGreaterOnRight = true;
                break;
            }

            q = q->next;
        }
        
        if(isGreaterOnRight == false){

            if(newHead == NULL){
                newHead = p;
            }
            
            prev = p;
            p = p->next;
        }
    }
    
    return newHead;
}