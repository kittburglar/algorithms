ListNode* reverseList(ListNode* head) {
    if (!head) {
        return NULL;
    }

    ListNode *t = new ListNode(head->val);
    head = head->next;

    while(head) {
        ListNode *prev = new ListNode(head->val);
        prev->next = t;
        t=prev;
        head = head->next;
    }

    return t;
}
