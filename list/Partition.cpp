#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *p, *q1, *q2, *q3, *r;

        if(head == NULL)
            return head;

        p = head;
        if(p->val < x){
            q1 = p;         //list(val < x)end
            q2 = NULL;      //list(val >= x)start
            q3 = NULL;      //list(val >= x)end
        }
        else{
            q1 = NULL;
            q2 = p;
            q3 = q2;
        }

        while(p != NULL && p->next != NULL){
            if(p->next->val < x){
                if(q1 == NULL){
                    q1 = p->next;
                    head = q1;
                }
                else{
                    q1->next =p->next;
                }

				r = p->next;
                while(r->next != NULL){
                    if(r->next->val < x){
                        r = r->next;
                    }
                    else
                        break;
                }

                if(q2 == NULL){
                    if(r->next == NULL){
                        break;
                    }
                    else{
						q1 = r;
                        q2 = r->next;
						q3 = q2;
						p = q3;
                    }
                }

                else{
                    if(r->next == NULL){
						q1 = r;
                        q3->next = r->next;
						q1->next = q2;
						p = q3;
						break;
                    }
                    else{
						q1 = r;
                        q3->next = r->next;
						q1->next = q2;
						q3 = q3->next;
						p = q3;
					}
				}
            }


            else{
                if(q2 == NULL){
                    q2 = p->next;
                    q3 = q2;
                }

                r = p->next;
                while(r->next != NULL){
                    if(r->next->val >= x){
                        r = r->next;
                    }
                    else
                        break;
                }

                if(q1 == NULL){
                    if(r->next == NULL){
                        break;
                    }
                    else{
                        q3 = r;
                        q1 = r->next;
                        head = q1;
                    }
                }

                else{
                    if(r->next == NULL){
                        break;
                    }
                    else{
                        q3 = r;
                        q1->next = r->next;
						q1 = r->next;
					}
				}
				q3->next = q1->next;
				q1->next = q2;
				p = q3;
            }

        }

        return head;
    }

int main()
{
	Solution S;
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(2);
	ListNode *l3 = new ListNode(3);
	ListNode *l4 = new ListNode(4);
	ListNode *p, *l5 = new ListNode(1);

	l1->next = l5;
	
	l3 = S.partition(l1, 2);

	cout << "print:\n";
	p = l3;
	while(p != NULL){
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;

	return 0;
}
