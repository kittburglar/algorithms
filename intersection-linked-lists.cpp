class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int firstLength = 0;
        int secondLength = 0;
        ListNode *headARunner = headA;
        ListNode *headBRunner = headB;
        
        
        while(headARunner){
            firstLength++;
            headARunner = headARunner->next;
        }
        while(headBRunner){
            secondLength++;
            headBRunner = headBRunner->next;
        }
        
        headARunner = headA;
        headBRunner = headB;
        
        if(firstLength < secondLength){
            for(int i = 0; i < (secondLength - firstLength); i++){
                headBRunner = headBRunner->next;
            }
        }
        else if(firstLength > secondLength){
            for(int i = 0; i < (firstLength - secondLength); i++){
                headARunner = headARunner->next;
            }
        }
        
        while(headARunner != headBRunner){
            headARunner = headARunner->next;
            headBRunner = headBRunner->next;
        }
        
        return headARunner;
    }
};
