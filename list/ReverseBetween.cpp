/*************************************************************************
	> File Name: ReverseBetween.cpp
	> Author: zhanchengjun
	> Mail: zhanchengjun02@gmail.com 
	> Created Time: Sun 07 Dec 2014 09:42:39 PM CST
 ************************************************************************/
#include "List.h"
#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n){
		ListNode *p, *q, *q1, *q2, *r1, *r2;
		ListNode **stack;
		int i, j;

		if(head == NULL || m == n){
			return head;
		}

		stack = (ListNode **)malloc((n-m+1) * sizeof(ListNode *));

		p = head;
		j = 0;
		for(i = 0; i < m-1; i++){
			p = p->next;
		}
		for(; i < n; i++){
			stack[j++] = p;
			p = p->next;
		}
		j = j - 1;
		q = p;
		
		if(m == 1){
			head = stack[j];
			for(; j > 0; j--){
				stack[j]->next = stack[j-1];
			}
			stack[0]->next = q;
		}
		else{
			p = head;
			for(i = 0; i < m-2; i++){
				p = p->next;
			}
			p->next = stack[j];

			for(; j > 0; j--){
				stack[j]->next = stack[j-1];
			}
			stack[0]->next = q;
		}

		return head;


/*
		p = head;
		for(i = 0; i < m-1; i++){
			p = p->next;
		}
		q1 = p;

		for(; i < n-1; i++){
			p = p->next;
		}
		q2 = p;

		p = head;
		if(m == 1){
			if(n == 2){
				head = q2;
				q1->next = q2->next;
				q2->next = q1;
			}

			else{
				for(i = 0; i < n-2; i++){
					p = p->next;
				}
				r2 = p;

				head = q2;
				p = q2->next;
				r2->next = q1;
				q2->next = q1->next;
				q1->next = p;
			}
		}
		else if(m == n-1){
			for(i = 0; i < m-2; i++){
				p = p->next;
			}
			r1 = p;

			p = q2->next;
			r1->next = q2;
			q2->next = q1;
			q1->next = p;
		}
		else{
			for(i = 0; i < m-2; i++){
				p = p->next;
			}
			r1 = p;

			for(; i < n-2; i++){
				p = p->next;
			}
			r2 = p;

			p = q1->next;
			q1->next = q2->next;
			q2->next = p;
			r1->next = q2;
			r2->next = q1;
		}

		return head;
*/	}
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

cout << "hahahahha" << endl;
	l1 = S.reverseBetween(l1, 3, 5);

	printList(l1);

	return 0;
}
