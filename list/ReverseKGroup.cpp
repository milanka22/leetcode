/*************************************************************************
	> File Name: ReverseBetween.cpp
	> Author: zhanchengjun
	> Mail: zhanchengjun02@gmail.com 
	> Created Time: Sun 07 Dec 2014 09:42:39 PM CST
 ************************************************************************/
#include "List.h"
#include <stdlib.h>
#include<iostream>
using namespace std;

class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k){
		int len, n, i, j;
		ListNode *p, *q, **stack;

		if(head == NULL || k < 2){
			return head;
		}

		len = lenOfList(head);
		if(k > len){
			return head;
		}

		stack = (ListNode **) malloc(k * sizeof(ListNode *));


		n = len / k;
		p = head;
		for(i = 0; i < n; i++){
			for(j = 0; j < k; j++){
				stack[j] = p;
				p = p->next;
			}
			j = j - 1;
			
			if(i == 0){
				head = stack[j];
			}
			else{
				q->next = stack[j];
			}

			for(; j > 0; j--){
				stack[j]->next = stack[j-1];
			}
			q = stack[0];
			q->next = p;
		}

		return head;
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
	l4->next = l5;

	printList(l1);

	l1 = S.reverseKGroup(l1, 5);

	printList(l1);

	return 0;
}
