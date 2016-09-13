/**
*  BST: binary search tree
*  这原本是hackerrank上的一道基础题，现在逐渐完善
*  @功能： 1. 建树 2. 判断树的高度 3. 节点数 4. 叶节点数
*
*   测试数据：一共7个节点
*                     3    
*                   /   \
*                  2     5 
*                 /     / \
*                1     4   6
*                           \
*                            7   
*
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* left;
    struct Node* right;
    int data;
}Node;

Node* newNode(int data)
{
    Node* node=(Node*)malloc(sizeof(Node));
    node->left=node->right=NULL;
    node->data=data;
    return node;
}



/* 将root == NULL的返回值置为-1或者0，结果不一样*/
int getHeight(Node* root)
{
	if(root == NULL)
		return -1;
    /* 返回为0， 结果是从根节点到叶子节点的节点数，
    *  返回为-1， 是经历的路径长度 */
	int left_height = getHeight(root->left);
	int right_height = getHeight(root->right);
	return (left_height > right_height ? left_height  : right_height ) + 1 ;
}

/* The number of node*/
int node_num_tree(Node* root)
{
    if(root == NULL)
        return 0;
    /* 这里的返回 0 还是有区别的 */
    return 1 + node_num_tree(root->left) + node_num_tree(root->right);
}

/* the numbers of leaves */
int leaf_num_tree(Node* root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    return leaf_num_tree(root->left) + leaf_num_tree(root->right);

}
Node* insert(Node* root,int data)
{
    if(root==NULL)
        return newNode(data);
    else{
        Node* cur;
        if(data<=root->data){
            cur=insert(root->left,data);
            root->left=cur;
        }
        else{
            cur=insert(root->right,data);
            root->right=cur;
        }

    }
    return root;
}
int main()
{
    freopen("22.in","r",stdin);
    Node* root=NULL;
    int T,data;
    scanf("%d",&T);
    while(T-- > 0){
        scanf("%d", &data);
        root = insert(root, data);
    }
    int height=getHeight(root);
    printf("The height of tree is %d\n",height);
    int num = node_num_tree(root);
    printf("\nThe node_num of tree is %d\n", num);
    int leaf = leaf_num_tree(root);
    printf("\nthe leaves of tree is %d\n", leaf);
    return 0;

}
