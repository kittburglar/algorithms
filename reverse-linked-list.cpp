class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return head;
        }
        
        if(!head->next){
            return head;
        }
        
        ListNode* prevNode = head;
        ListNode* runnerNode = head->next;
        ListNode* nextNode = head->next->next;
        prevNode->next = NULL;
        
        while(nextNode){
            runnerNode->next = prevNode;
            
            prevNode = runnerNode;
            runnerNode = nextNode;
            nextNode = nextNode->next;
        }
        runnerNode->next = prevNode;
        return runnerNode;
    }
};
