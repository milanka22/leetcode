/*************************************************************************
	> File Name: CopyRandomList.cpp
	> Author: zhanchengjun
	> Mail: zhanchengjun02@gmail.com 
	> Created Time: Sat 29 Nov 2014 12:14:17 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head){
		RandomListNode *p = head;
		RandomListNode *q, *r;
		RandomListNode *off[2048];
		int offset[2048];
		int i = 0, j = 0, k = 0;

		if(p == NULL){
			return NULL;
		}
		
		RandomListNode *nhead = new RandomListNode(p->label);
		offset[i++] = offsetToHead(head, p);
		
		q = nhead;
		while(p->next != NULL){
			RandomListNode *add = new RandomListNode(p->next->label);
			q->next = add;
			q = q->next;
			p = p->next;
			offset[i++] = offsetToHead(head, p);
		}
cout << i << endl;

		p = nhead;
		k = 0;
		while(p != NULL){
			off[k++] = p;
			p = p->next;
		}

		p = nhead;
		for(j = 0; j < i; j++){
cout << offset[j] << endl;
			if(offset[j] == -1){
				q = NULL;
			}
			else{
				q = off[offset[j]];
			}
			p->random = q;
			p = p->next;
		}

		return nhead;
	}

	int offsetToHead(RandomListNode *head, RandomListNode *r){
		RandomListNode *p = head;
		RandomListNode *q = r->random;
		int i = 0;

		if(q == NULL)
			return -1;

		while(p != q){
			p = p->next;
			i++;
		}

		return i;
	}
};

int main()
{
	Solution S;
	RandomListNode *r = new RandomListNode(1);
	RandomListNode *p;

	p = S.copyRandomList(r);

	while(p != NULL){
		cout << p->label << '\t';
		p = p->next;
	}
	return 0;
}
