ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy = ListNode(INT_MAX);
    ListNode* runner = &dummy;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            runner->next = l1;
            l1 = l1->next;
        } else {
            runner->next = l2;
            l2 = l2->next;
        }

        runner = runner->next;
    }

    if (!l1) {
        runner->next = l2;
    } else if (!l2) {
        runner->next = l1;
    }

    return dummy.next;
}
