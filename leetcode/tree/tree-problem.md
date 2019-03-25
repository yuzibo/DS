---
title: "树的简单题目"
category: tree
layout:
---
* content
{:toc}

# 104 Maximum Depth of Binary Tree

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

```c
    3
   / \
  9  20
    /  \
   15   7
```

code :

```c
int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int l_d = maxDepth(root->left);
    int r_d = maxDepth(root->right);
    return l_d > r_d ? (l_d + 1) :(r_d + 1);

}
```

# 111 Minimum Depth of Binary Tree
题目的思路同上面的一样，有一个问题就是注意

```c
	1
       /
      2
```
代码：
```c
int minDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int l_d = minDepth(root->left) + 1;
    int r_d = minDepth(root->right) + 1;

    if (root->left == NULL){
        return r_d;
    } else if (root->right == NULL) {
        return l_d;
    } else {
        return l_d < r_d ? l_d : r_d;
    }
}
```

# 100 same tree

```c
Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
```

Solution:

```c
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p != NULL && q != NULL){
        if (p->val != q->val)
            return false;
        if (!isSameTree(p->left, q->left))
            return false;
        if(!isSameTree(p->right, q->right))
            return false;
    } else {

        return p == q;
    }
    return true;

}
```

# 101 Symmetric tree

## Description

```c
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
```
```c
bool checkTree(struct TreeNode *a, struct TreeNode *b){


    if(a == NULL && b == NULL)
        return true;
    if (a == NULL || b == NULL)
        return false;
        return (a->val == b->val) && checkTree(a->left, b->right) && checkTree(a->right, b->left);
}
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;
    return checkTree(root->left, root->right);
}
```
### 第二种解法
```c
/*struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
*/
typedef struct TreeNode *custom_elemnt;
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


bool isSymmetric(struct TreeNode *root)
{
    custom_elemnt temp;
    if (root == NULL)
        return true;

	struct double_linked_queue *queue = queue_init();
	insert_front(queue, root->left);
    insert_front(queue, root->right);
    while(!is_empty(queue)){
        struct TreeNode *t1 = get_front(queue);
         delete_front(queue);
        struct TreeNode *t2 = get_front(queue);
        delete_front(queue);
        if (t1 == NULL && t2 == NULL){
            continue;
        }
        if (t1 == NULL || t2 == NULL){
            return false;
        }
        if(t1->val != t2->val)
            return false;
        insert_front(queue, t1->left);
        insert_front(queue, t2->right);
        insert_front(queue, t1->right);
        insert_front(queue, t2->left);

    }
    return true;

}
```
但是效率上感觉没有提升多少啊　

# 965. Univalued Binary Tree
A binary tree is univalued if every node in the tree has the same value.

Return true if and only if the given tree is univalued.
Input: [1,1,1,1,1,null,1]
Output: true
Input: [2,2,2,5,2]
Output: false

```c
void is_check(struct TreeNode *tree, int *comp_val, int *flag)
{

    if (tree->val != *comp_val){
        *flag = 0;
        return ;
    }
    if(tree->left)
         is_check(tree->left, comp_val, flag);
    if(tree->right)
        is_check(tree->right, comp_val,flag);
}
bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL)
        return true;
    int comp_val = root->val, flag = 1;
    is_check(root, &comp_val, &flag);
    if (flag == 0)
        return false;
    else
        return true;
}
```
