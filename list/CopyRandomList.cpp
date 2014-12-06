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
		int offset;
		int i;

		if(p == NULL){
			return NULL;
		}
		
		RandomListNode *nhead = new RandomListNode(p->label);
		offset = offsetToHead(head, p);
		
		while(p->next != NULL){
			p = p->next;
			nhead = addNodeToRandomList(nhead, p->label);
			//offset[i++] = offsetToHead(head, p);
		}

		p = nhead;
		q = head;
		offset = offsetToHead(head, q);

		if(offset == -1){
			r = NULL;
		}
		else{
			r = nhead;
			for(i = 0; i < offset; i++){
				r = r->next;
			}
		}

		p->random = r;

		while(p->next != NULL){
			p = p->next;
			q = q->next;
			offset = offsetToHead(head, q);

			if(offset == -1){
				r = NULL;
			}
			else{
				r = nhead;
				for(i = 0; i < offset; i++){
					r = r->next;
				}
			}

			p->random = r;
		}

/*
		p = nhead;
		for(j = 0; j < i; j++){
			if(offset[j] == -1){
				q = NULL;
			}
			else{
				q = nhead;
				for(k = 0; k < offset[j]; k++){
					q = q->next;
				}
			}
			p->random = q;
			p = p->next;
		}
*/
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


	RandomListNode *addNodeToRandomList(RandomListNode *r, int label){
		RandomListNode *p, *q;
		RandomListNode *add = new RandomListNode(label);

		q = r;
		p = getEndOfRandomList(q);
		p->next = add;

		return r;
	}

	RandomListNode *getEndOfRandomList(RandomListNode *r){
		RandomListNode *p = r;

		while(p->next != NULL){
			p = p->next;
		}

		return p;
	}
};

int main()
{
	return 0;
}
