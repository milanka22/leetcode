class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *p = head;
        int val;
        
        if(p == NULL){
            return p;
        }
        
        val = p->val;
        while(p->next != NULL){
            if(val == p->next->val){
                p->next = p->next->next;
				if(p->next == NULL){
				    break;
				}
            }
            else{
                val = p->next->val;
				p = p->next;
			}
        }
        
        return head;
    }
};
