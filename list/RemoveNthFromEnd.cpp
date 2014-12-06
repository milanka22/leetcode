/*************************************************************************
	> File Name: RemoveNthFromEnd.cpp
	> Author: zhanchengjun
	> Mail: zhanchengjun02@gmail.com 
	> Created Time: Sat 29 Nov 2014 03:19:47 PM CST
 ************************************************************************/

#include "List.h"
#include<iostream>
using namespace std;

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
		int i, len;
		ListNode *p = head;

		len = lenOfList(p);
		i = len - n;

		if(i == 0){
			head = head->next;
		}
		
		else{
			while(i-- > 1){
				p = p->next;
			}
			p->next = p->next->next;
		}

		return head;
    }
};

int main()
{
	int i;
	ListNode *p = new ListNode(0);
	Solution S;
	ListNode *l;

	for(i = 1; i < 5; i++){
		p = addNodeToList(p, i);
	}

	l = S.removeNthFromEnd(p, 1);

	printList(l);

	l = S.removeNthFromEnd(p, 4);

	printList(l);

	return 0;
}
