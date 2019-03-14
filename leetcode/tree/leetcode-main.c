/*
 *     File Name: leetcode-main.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: 2019年03月14日 星期四 11时06分00秒
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * * Definition for a binary tree node.
 * * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * * };
 **/
/* 自己实现链对，命名不一样*/
struct TreeNode {
	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
};
/* 上面的结构体可以随时替换 */
struct queue_node {
	struct TreeNode *bst;// 二叉树成员
	struct queue_node *next;
};
struct link_queue {
	struct queue_node *front, *rear;
};

/**
struct TreeNode* sortedArrayToBST(int* nums, int numsSize)；
}
*/

struct TreeNode* sortedArrayToBST(int *nums, int numsSize);

void display(struct TreeNode *);
// 这里需要你自己把leetcode的调用函数放到main函数中去
// 需要改变的量就是调用函数的参数

// create a new linked list node
struct queue_node *new_node(struct TreeNode *tree)
{
	struct queue_node *temp = (struct queue_node *)malloc(sizeof(struct queue_node));
	temp->bst = tree;
	temp->next = NULL;
	return temp;
}
// 队列的api
struct link_queue *queue_init()
{
	struct link_queue *q = (struct link_queue *)malloc(sizeof(struct link_queue));
	q->front = q->rear = NULL;
	return q;
}
/*
*  empty
*/
int queue_empty(struct link_queue *root)
{
	if (root->front == NULL &&  root->rear == NULL)
		return 1;
	else
		return 0;

}
/*
* 入队
*/
void queue_in(struct link_queue *root, struct TreeNode *tree)
{
	struct queue_node *node = new_node(tree);
	if(root->rear == NULL)
	{
		root->front = root->rear = node;
		return;
	}

	root->rear->next = node;
	root->rear = node;
}

// out queue,这里的这个返回值可以，也可以在参数中返回
struct queue_node *queue_out(struct link_queue *root)
{
	if (root->rear == NULL)
		return NULL;
	struct queue_node *q = root->front;
	root->front= root->front->next;


	if(root->front == NULL)
	{
		root->rear = NULL;
		printf("queue has been emptyed\n");
		//return NULL;
	}
	return q;
}

/*复制数据的 */
struct TreeNode *newNode(int data)
{
	struct TreeNode *p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	p->val = data;
	p->left = p->right = NULL;
}
struct TreeNode *createBinaryTree(struct TreeNode *root, int *array, int pos, int nums)
{
	//struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	if (pos < nums) {
		struct TreeNode *p = newNode(array[pos]);
		root = p;
		root->left = createBinaryTree(root->left, array, pos*2 + 1, nums);
		root->right = createBinaryTree(root->right, array, pos*2 + 2, nums);
	}
	return root;
}

void show(struct TreeNode *p)
{
	if(p == NULL)
		return ;
	else {
		show(p->left);
		if(p->val == -1)
			printf("#\t");
		else
			printf("%d\t", p->val);
		show(p->right);
	}
}

// 应该是层次遍历，借助于队列

void display(struct TreeNode *root)
{
	struct queue_node *temp;
	struct link_queue *queue = queue_init();
	queue_in(queue, root);
	printf("the first val is %d\n", queue->front->bst->val);
	if (root == NULL)
		printf("haha\n");
	printf("进行层次遍历\n");
	printf("the queue is %d\n", queue_empty(queue));
	while(!queue_empty(queue))
	{
		temp = queue_out(queue);
		printf("%d,", temp->bst->val);
	/*	if (temp->bst->left == NULL && temp->bst->right == NULL)
			printf("NULL,");
	*/
		if (temp->bst->left != NULL)
			queue_in(queue, temp->bst->left);
		if (temp->bst->right != NULL)
			queue_in(queue, temp->bst->right);
	}
}

#define customer 0

int main()
{

	int nums[] = {-10, -3, 0, 5, 9};

	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));

	root = sortedArrayToBST(nums, (sizeof(nums)/sizeof(nums[0])));

#if customer
	root = createBinaryTree(root, nums, 0, sizeof(nums)/sizeof(nums[0]));
#endif
	display(root);

//	printf("中序遍历\n:");
//	show(root);
	return 0;
}

