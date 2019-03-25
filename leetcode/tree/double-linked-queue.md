使用双链表完成队列的使用，注意在进行层次遍历的时候
出对的顺序与单链表不一样

```c
/*
 *     File Name: double-linked-queue.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: 2019年03月24日 星期日 10时07分37秒
 *	-10
 *      /  \
 *     -3   0
 *     / \
 *    5   9
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode, *custom_elemnt;

//typedef int custom_elemnt;
struct queue_node {
	//int data; // 后期可以使用typedef
	custom_elemnt bst;
	struct queue_node *prev, *next;
};

struct double_linked_queue {
	struct queue_node *front, *rear;
	int size; // mark number of the queue
};
// operation
void insert_front(struct double_linked_queue *root,custom_elemnt bst);
void insert_rear(struct double_linked_queue *root,custom_elemnt bst);
void delete_front(struct double_linked_queue *root);
void delete_rear(struct double_linked_queue *root);
custom_elemnt get_front(struct double_linked_queue *root);
custom_elemnt get_rear(struct double_linked_queue *root);
//int size(str);
bool is_empty(struct double_linked_queue *root);
void erase(struct double_linked_queue *root);

bool is_empty(struct double_linked_queue *root)
{
	if(root->size == 0)
		return true;
	else
		return false;
}
// 相当于c++中的构造函数，其值可以变换
struct queue_node *alloc_node(custom_elemnt tree)
{
	struct queue_node *temp = (struct queue_node *)malloc(sizeof(struct queue_node));
	if (!temp){
		printf("fail to alloc temp\n");
		exit(1);
	}
	temp->bst = tree;
	temp->prev = temp->next = NULL;
	return temp;
}
struct double_linked_queue *queue_init()
{
	struct double_linked_queue *q = (struct double_linked_queue *)malloc(sizeof(struct double_linked_queue));
	q->front = q->rear = NULL;
	q->size = 0;
	return q;
}
void insert_front(struct double_linked_queue *root, custom_elemnt tree)
{
	/* new_node have checked the malloc */
	struct queue_node *new_node = alloc_node(tree);

	/* if queue is empty */
	if (root->front == NULL){
		root->front = root->rear = new_node;
	}
	else
	{
		new_node->next = root->front;
		root->front->prev = new_node;
		root->front = new_node;
	}
	root->size++;
}
void insert_rear(struct double_linked_queue *root, custom_elemnt val)
{
	struct queue_node *new_node = alloc_node(val);
	if (root->rear == NULL){ // is empty ?
		root->front = root->rear = new_node;
	}
	else
	{
		new_node->prev = root->rear;
		root->rear->next = new_node;
		root->rear = new_node;
	}
	root->size++;
}
void delete_front(struct double_linked_queue *root){
	struct queue_node *temp = (struct queue_node *)malloc(sizeof(struct queue_node));

	if (is_empty(root))
		printf("queue is empty\n");
	// note : 只能在对头　对尾删除，所以操作受限
	else {
		temp = root->front;
		root->front = root->front->next;
		// only one element
		if(root->front == NULL)
			root->rear = NULL;
		else
			root->front->prev = NULL;
		free(temp);
		root->size--;

	}
}
void delete_rear(struct double_linked_queue *root)
{
	if (is_empty(root))
		printf("is empty\n");
	struct queue_node *temp = root->rear;
	root->rear = root->rear->prev;
	if (root->rear == NULL)
		root->front = NULL;
	else
		root->rear->next = NULL;
	free(temp);
	root->size--;
}
custom_elemnt get_front(struct double_linked_queue *root)
{
	if(is_empty(root))
		printf("no data\n");
	return root->front->bst;
}
custom_elemnt get_rear(struct double_linked_queue *root)
{
	if (is_empty(root))
		printf("no data \n");
	return root->rear->bst;
}
void erase(struct double_linked_queue *root)
{
	root->rear = NULL;
	while(root->front != NULL)
	{
		struct queue_node *temp = root->front;
		root->front = root->front->next;
		free(temp);
	}
	root->size = 0;
}
////////////////////////
//
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
	custom_elemnt temp;
	struct double_linked_queue *queue = queue_init();
	insert_front(queue, root);
	printf("the first val is %d\n", queue->front->bst->val);
	if (root == NULL)
		printf("haha\n");
	printf("进行层次遍历\n");
	while(!is_empty(queue))
	{
		temp = get_front(queue);
		printf("%d,", temp->val);
		delete_front(queue);
	//	if (temp->bst->left == NULL && temp->bst->right == NULL)
	//		printf("NULL,");

		if (temp->left != NULL)
			insert_rear(queue, temp->left);
		if (temp->right != NULL)
			insert_rear(queue, temp->right);
	}
}

#define customer 1

int main()
{

	int nums[] = {-10, -3, 0, 5, 9};

	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));


#if customer
	root = createBinaryTree(root, nums, 0, sizeof(nums)/sizeof(nums[0]));
#endif
	display(root);

	printf("中序遍历\n:");
	show(root);
	printf("\n");
	return 0;
}
```
