/*************************************************************************
	> File Name: RotateList.cpp
	> Author: zhanchengjun
	> Mail: zhanchengjun02@gmail.com 
	> Created Time: Thu 27 Nov 2014 08:02:18 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *p, *q;
        int len, i, j;
        
        p = head;
        len = 0;
        while(p != NULL){
            len += 1;
            p = p->next;
        }
        
        if(len == 0)
            return head;
        
        i = k % len;
        if(i == 0)
            return head;
        
        i = len -i;
        p = head;
        for(j = 0; j < i-1; j++){
            p = p->next;
        }
        q = p->next;
        p->next = NULL;
        
        p = q;
        while(q->next != NULL){
            q = q->next;
        }
        
        q->next = head;
        head = p;
        
        return head;
    }
};
