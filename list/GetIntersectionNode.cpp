#include <stdio.h>
#include "List.h"
#include <iostream>

using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *pa, *pb, *p = NULL;

		pa = headA;

		while(pa != NULL){
			p = pa->next;
			pb = headB;

			while(pb != p && pb != NULL){
				pb = pb->next;
			}
			if(pb == p){
				break;
			}

			pa = pa->next;
     
		}

		return p;
    }
};


int main()
{
	int i;
	Solution S;

	ListNode *l;
	ListNode *l1 = new ListNode(11);
	ListNode *l2 = new ListNode(22);
	ListNode *l3 = new ListNode(33);

	for(i = 1; i < 10; i++){
		l1 = addNodeToList(l1, i);
	}

//	l2->next = l1;
	l3->next = l1;

	l = S.getIntersectionNode(l2, l3);

	if(l == NULL)
		cout << "NULL" << endl;
	else
		cout << l->val << endl;

	return 0;
}
