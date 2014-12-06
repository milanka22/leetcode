#include "List.h"
#include <iostream>

using namespace std;

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *p1, *p2, *head, *p;

		if(l1 == NULL)
			return l2;
		if(l2 == NULL)
			return l1;

		head = l1;
		p = l2;
		if(l1->val > l2->val){
			head = l2;
			p = l1;
		}
		p1 = head;
		p2 = p;

		if(p1->next == NULL){
			p1->next = p2;
			return head;
		}
		while(p1->next != NULL && p2 != NULL){
			p = p1->next;
			if(p->val <= p2->val && p->next != NULL){
				p1 = p1->next;
			}
			else if(p->val <= p2->val && p->next == NULL){
				p->next = p2;
				break;
			}
			else if(p->val > p2->val && p2->next != NULL){
				p1->next = p2;
				p1 = p2;
				p2 = p;
			}
			else if(p->val > p2->val && p2->next == NULL){
				p1->next = p2;
				p2->next = p;
				break;
			}
		}

		return head;
    }
};

int main()
{
	int i;
	Solution S;

	ListNode *l;
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(2);
	ListNode *l3 = new ListNode(33);

	for(i = 1; i < 10; i++){
		l1 = addNodeToList(l1, i);
	}

	for(i = 4; i < 11; i += 2){
		l2 = addNodeToList(l2, i);
	}

	l = S.mergeTwoLists(l1, l2);

	if(l == NULL)
		cout << "NULL" << endl;

	else 
		printList(l);

	return 0;
}

