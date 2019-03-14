#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

void toBST(struct TreeNode *root, int *nums, int head, int tail)
{
	int mid = (head + tail) / 2;
	root->val = nums[mid];

	if (head <= mid - 1){
		root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
		toBST(root->left, nums, head, mid - 1);
	}
	else
		root->left = NULL;

	if (mid + 1 <= tail)
	{
		root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
		toBST(root->right, nums, mid + 1, tail);
	}
	else
		root->right = NULL;

}


struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
	struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left = NULL;
    root->right = NULL;
	int head = 0;
    int tail;
    if (numsSize >= 1) {
	    tail = numsSize - 1;
	    toBST(root, nums, head, tail);
    }
    else
        return root = NULL ;

    return root;
}
