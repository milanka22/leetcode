/*************************************************************************
	> File Name: main.cpp
	> Author: zhanchengjun
	> Mail: zhanchengjun02@gmail.com 
	> Created Time: Fri 28 Nov 2014 10:04:14 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include "Tree.h"

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL){
			return NULL;
        }
		
		TreeNode *root = new TreeNode(head->val);

		while(head->next != NULL){
			root = insertNodeToBST(root, head->next->val);
			head = head->next;

			cout << "PreOrder:\t";
			printPreOrder(root);
			cout << endl;

			cout << "MidOrder:\t";
			printMidOrder(root);
			cout << endl;
		}

		return root;
    }

	TreeNode *insertNodeToBST(TreeNode *t, int val){
		TreeNode *p = new TreeNode(val);
		TreeNode *q, *root;
		TreeNode *array[100];
		int i = 0;

		q = t;
		while(q->right != NULL){
			array[i++] = q;
			q = q->right;
		}
		q->right = p;
		cout << "i = " << i << endl;

		if(i == 0){
			return t;
		}

		p = array[--i];
		while(i > 0 && (getHeightOfTree(p->right) - getHeightOfTree(p->left) < 2)){
			p = array[--i];
		}

		cout << "i = " << i << endl;
		cout << "h = " << getHeightOfTree(p->right) - getHeightOfTree(p->left) << endl;

		if(i < 0){
			return t;
		}

		else if(i == 0){
			if(getHeightOfTree(p->right) - getHeightOfTree(p->left) < 2){
				return t;
			}
			else{
				root = t->right;
				t->right = root->left;
				root->left = t;
				return root;
			}
		}

		else{
			q = array[--i];
			root = t;
			q->right = p->right;
			p->right = p->right->left;
			q->right->left = p;
		}
			
		return root;
	}
    
};

int main()
{
	Solution S;
	TreeNode *t;
	ListNode *l;

	l = new ListNode(1);
	l = addNodeToList(l, 2);
	l = addNodeToList(l, 3);
	l = addNodeToList(l, 4);
	l = addNodeToList(l, 5);
	l = addNodeToList(l, 6);

	t = S.sortedListToBST(l);

	return 0;
}
