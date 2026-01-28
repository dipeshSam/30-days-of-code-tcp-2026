#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Recursive DFS function
int dfs(struct TreeNode* root, int *globalMax) {
    if (root == NULL)
        return 0;

    // Max path sum from left and right subtrees
    int leftGain = max(0, dfs(root->left, globalMax));
    int rightGain = max(0, dfs(root->right, globalMax));

    // Path passing through this node
    int currentPath = root->val + leftGain + rightGain;

    // Update global maximum path sum
    *globalMax = max(*globalMax, currentPath);

    // Return max gain if we continue the path upwards
    return root->val + max(leftGain, rightGain);
}

// Main function required by LeetCode
int maxPathSum(struct TreeNode* root) {
    int globalMax = INT_MIN;
    dfs(root, &globalMax);
    return globalMax;
}

// Utility function to create a new tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// ------------------ TESTING ------------------
int main() {
    /*
        Example Tree:
                1
               / \
              2   3

        Expected Output: 6
    */

    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    int result = maxPathSum(root);
    printf("Maximum Path Sum = %d\n", result);

    return 0;
}
