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
