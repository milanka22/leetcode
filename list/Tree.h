/*************************************************************************
	> File Name: Tree.h
	> Author: zhanchengjun
	> Mail: zhanchengjun02@gmail.com 
	> Created Time: Fri 28 Nov 2014 10:07:24 PM CST
 ************************************************************************/
#include <stdio.h>
#include "List.h"

/**
 * Definition for binary tree
 */
struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getHeightOfTree(TreeNode *t);

ListNode *preOrderTraversal(TreeNode *t);

ListNode *midOrderTraversal(TreeNode *t);

ListNode *postOrderTraversal(TreeNode *t);

void printPostOrder(TreeNode *t);

void printMidOrder(TreeNode *t);

int getHeightOfTree(TreeNode *t)
{
	int hl, hr;
	TreeNode *p = t;
    
    if(p == NULL)
        return 0;

	hr = getHeightOfTree(p->right);
	hl = getHeightOfTree(p->left);

	if(hl < hr)
		return hr+1;
	else
		return hl+1;
}


ListNode *postOrderTraversal(TreeNode *t)
{
	ListNode *l = new ListNode(0);

	return l;
}

void printPostOrder(TreeNode *t)
{
	if(t->left != NULL){
		printPostOrder(t->left);
	}

	if(t->right != NULL){
		printPostOrder(t->right);
	}

	printf("%d\t", t->val);
}

void printMidOrder(TreeNode *t)
{
	if(t->left != NULL){
		printMidOrder(t->left);
	}

	printf("%d\t", t->val);

	if(t->right != NULL){
		printMidOrder(t->right);
	}
}

void printPreOrder(TreeNode *t)
{
	printf("%d\t", t->val);

	if(t->left != NULL){
		printPreOrder(t->left);
	}

	if(t->right != NULL){
		printPreOrder(t->right);
	}
}
