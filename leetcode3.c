struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prevnode, *currentnode, *nextnode;
    currentnode=nextnode=head;
    prevnode=NULL;
    while(currentnode!=NULL) {
        nextnode=currentnode->next;
        currentnode->next = prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head = prevnode;
    return head;
}
