/*************************************************************************
	> File Name: List.h
	> Author: zhanchengjun
	> Mail: zhanchengjun02@gmail.com 
	> Created Time: Fri 28 Nov 2014 03:24:17 PM CST
 ************************************************************************/
#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addNodeToList(ListNode *l, int val);

ListNode *getEndOfList(ListNode *l);

void printList(ListNode *l);

int len(ListNode *l);


ListNode *addNodeToList(ListNode *l, int val)
{
	ListNode *p, *q;
	ListNode *add = new ListNode(val);

	q = l;
	p = getEndOfList(q);
	p->next = add;

	return l;
}

ListNode *getEndOfList(ListNode *l)
{
	ListNode *p = l;

	while(p->next != NULL){
		p = p->next;
	}

	return p;
}

void printList(ListNode *l)
{
	ListNode *p = l;

	while(p->next != NULL){
		printf("%d\t", p->val);
		p = p->next;
	}

	printf("%d\n", p->val);
}

int lenOfList(ListNode *l)
{
	int len = 0;
	ListNode *p = l;

	while(p != NULL){
		len++;
		p = p->next;
	}

	return len;
}
