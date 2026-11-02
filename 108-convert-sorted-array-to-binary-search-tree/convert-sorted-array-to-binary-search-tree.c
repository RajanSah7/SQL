/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
normal sorted ARRAY to BST
struct TreeNode* root;
struct TreeNode* createNode(int data)
{
    struct TreeNode* newnode;
    newnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newnode->val = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}
 struct TreeNode* BST(struct TreeNode* root,int value)
 {
    if(root==NULL)
    {
        root = createNode(value);
    }

    if(root->val<value)
    {
        root->right = BST(root->right, value);
    }

    if(root->val>value)
    {
        root->left = BST(root->left, value);
    }

    return root;

 }
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    int i;
    root=NULL;
    for(i=0;i<numsSize;i++)
    {
        root = BST(root,nums[i]);
    }

    return root;
}*/
struct TreeNode* createNode(int data)
{
    struct TreeNode* newnode;
    newnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newnode->val = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

struct TreeNode* sortedArrayHelper(int* nums, int left, int right) {
    if (left > right) {
        return NULL;
    }
    
    int mid = left + (right - left) / 2;
    
    struct TreeNode* node = createNode(nums[mid]);
  
    node->left = sortedArrayHelper(nums, left, mid - 1);
    node->right = sortedArrayHelper(nums, mid + 1, right);
    
    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return sortedArrayHelper(nums, 0, numsSize - 1);
}