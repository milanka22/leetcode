/*************************************************************************
	> File Name: AddTwoNumbers.cpp
	> Author: zhanchengjun
	> Mail: zhanchengjun02@gmail.com 
	> Created Time: Thu 27 Nov 2014 07:59:54 PM CST
 ************************************************************************/
#include "List.h"
#include<iostream>
#include <stdio.h>

using namespace std;
 
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int a, b;
        int len1, len2;
        ListNode *p, *q, *head;

        p = l1;
        len1 = lenOfList(p);
        p = l2;
        len2 = lenOfList(p);
		cout << "len1 = " << len1 << endl;
		cout << "len2 = " << len2 << endl; 

        p = l1;
        q = l2;
        if(len1 < len2){
            p = l2;
            q = l1;
        }
        head = p;

        while(q->next != NULL){
            a = p->val + q->val;
            p->val = a % 10;
            p->next->val += (int)(a / 10);

            p = p->next;
            q = q->next;
        }
        p->val += q->val;

        while(p->next != NULL){
            if(p->val < 10){
                break;
            }
            a = p->val;
            p->val = a % 10;
            p->next->val += (int)(a / 10);
            p = p->next;
        }

        if(p->val >= 10){
            q = new ListNode(1);
            p->next = q;
            p->val = p->val % 10;
        }

		return head;

    }
};

int main()
{
	int i;

	Solution S;
	ListNode *l;
	ListNode *l1 = new ListNode(0);
	ListNode *l2 = new ListNode(12);

	for(i = 1; i < 10; i++){
		l1 = addNodeToList(l1, i);
	}

	for(i = 10; i > 0; ){
		l2 = addNodeToList(l2, i);
		i -= 2;
	}

	l = S.addTwoNumbers(l1, l2);

	printList(l);

	return 0;
}

