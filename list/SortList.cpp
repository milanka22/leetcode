/*************************************************************************
	> File Name: SortList.cpp
	> Author: zhanchengjun
	> Mail: zhanchengjun02@gmail.com 
	> Created Time: Sun 07 Dec 2014 10:32:06 PM CST
 ************************************************************************/
#include "List.h"
#include<iostream>
using namespace std;
class Solution {
public:
    ListNode *sortList(ListNode *head) {
		ListNode *p, *q, *r, *qn, *qm, *nhead;
		int k;

		if(head == NULL){
			return NULL;
		}

		k = head->val;
		q = head;
		qm = head;
		p = head->next;
		nhead = NULL;
		qn = NULL;
		while(p != NULL){
			if(p->val < k){
				if(nhead == NULL){
					nhead = p;
					qn = nhead;
				}
				else{
					qn->next = p;
					qn = qn->next;
				}
				p = p->next;
			}
			else if(p->val == k){
				r = p;
				p = p->next;
				r->next = qm->next;
				qm->next = r;
				qm = qm->next;
			}
			else{
				q->next = p;
				q = q->next;
				p = p->next;
			}
		}
		q->next = NULL;
	
	
		if(nhead != NULL){
			qn->next = NULL;
			nhead = sortList(nhead);
			q = qm->next;
			q = sortList(q);
			qm->next = q;

			qn = nhead;
			while(qn->next != NULL){
				qn = qn->next;
			}
			qn->next = head;

			return nhead;
		}
		else{
			return head;
		}
	}
};

int main()
{
	Solution S;
	ListNode *l1 = new ListNode(4);
	ListNode *l2 = new ListNode(2);
	ListNode *l3 = new ListNode(3);
	ListNode *l4 = new ListNode(5);
	ListNode *p, *l5 = new ListNode(4);

	l1->next = l4;
	l4->next = l3;
	l3->next = l5;
	l5->next = l2;

cout << "hahahahha" << endl;
	p = S.sortList(l1);

	printList(p);

	return 0;
}
