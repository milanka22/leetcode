/*************************************************************************
	> File Name: ReorderList.cpp
	> Author: zhanchengjun
	> Mail: zhanchengjun02@gmail.com 
	> Created Time: Sun 07 Dec 2014 09:42:39 PM CST
 ************************************************************************/
#include "List.h"
#include<iostream>
using namespace std;

class Solution {
public:
    void reorderList(ListNode *head) {
		int len, i, j, n;
		ListNode *p, *q, *a[10000];

		if(head != NULL){
		len = lenOfList(head);
		n = (int) (len / 2);

		p = head;
		for(i = 0; i < n; i++){
			p = p->next;
		}
		q = p;
		p = p->next;
		q->next = NULL;
		for(i = 0; i < (len-n-1); i++){
			a[i] = p;
			p = p->next;
		}

		p = head;
		for(j = 0; j < (len-n-1); j++){
			q = p->next;
			p->next = a[--i];
			p->next->next = q;
			p = q;
		}
		}
    }
};

int main()
{
	Solution S;
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(2);
	ListNode *l3 = new ListNode(3);
	ListNode *l4 = new ListNode(4);
	ListNode *p, *l5 = new ListNode(5);

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	//l4->next = l5;

cout << "hahahahha" << endl;
	S.reorderList(l1);

	printList(l1);

	return 0;
}
