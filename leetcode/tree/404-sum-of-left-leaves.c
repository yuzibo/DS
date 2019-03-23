/*
 *     File Name: 404-sum-of-left-leaves.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: 2019年03月19日 星期二 20时39分29秒
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void traverse(struct TreeNode *root, int *sum, int left_flag)
{
    if (root == NULL)
        return ;
    if(root->left == NULL && root->right == NULL && left_flag){
        *sum = *sum + root->val;
        return;
    }
    traverse(root->left, sum, 1);
    traverse(root->right, sum, 0);


}
int sumOfLeftLeaves(struct TreeNode* root) {
   int sum = 0;
    traverse(root, &sum, 0);
    return sum;

}
/*   第二种方式 */

void traverse(struct TreeNode *root, int *sum, int left_flag)
{
    if (root == NULL)
        return ;
    if(root->left == NULL && root->right == NULL && left_flag){
        *sum = *sum + root->val;
        return;
    }
    else {
        traverse(root->left, sum, 1);
        traverse(root->right, sum, 0);
    }
}
int sumOfLeftLeaves(struct TreeNode* root) {
   int *sum =(int *)malloc(sizeof(int));
    *sum = 0;
    traverse(root, sum, 0);
    return *sum;
}
/* 8 ms */
int sumOfLeftLeaves(struct TreeNode* root) {
/*
    int *sum =(int *)malloc(sizeof(int));
    *sum = 0;
    traverse(root, sum, 0);
    return *sum;
*/
    if (root == NULL)
        return 0;
    if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
        return root->left->val + sumOfLeftLeaves(root->right);
    else{
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
}
/*
 * 性能上还是没有进步 */
int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    return (ISCHILD(root->left) ? root->left->val : sumOfLeftLeaves(root->left)) + sumOfLeftLeaves(root->right);
}
