doublylinkedlist_merge(doublylinkedlist &other)
{
    doublylinkedlist mergelist;
    Node*curr1 = this -> head;
    Node*curr2 = other.head;

    while(curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data < curr2 -> data){
            mergedlist.insert(curr1->data);
            curr1 = curr1->next;
        }
        else {
            mergedlist.insert(curr2 -> data);
            curr2 = curr2 -> next;
        }
    }
    while(curr1 != NULL){
        mergedlist.insert(curr1->data);
        curr1 = curr1 -> next;

    }
    return mergedlist;
}