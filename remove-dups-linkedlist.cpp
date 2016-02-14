class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head){
            return head;
        }
        unordered_map<int, int> myMap;
        myMap[head->val]++;
        ListNode* runner = head;
        while(runner->next){
            myMap[runner->next->val]++;
            if(myMap[runner->next->val] > 1){
                runner->next = runner->next->next;
            }
            else{
            runner = runner->next;
            }
        }
        return head;
    }
};
