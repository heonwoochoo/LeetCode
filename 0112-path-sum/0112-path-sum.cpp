/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
void DFS(TreeNode* node, int curSum, int targetSum, bool& res)
{
    if (res == true) return;
    curSum += node->val;
    if (node->left == nullptr && node->right == nullptr && curSum == targetSum)
    {
       res = true;
    }
    if (node->left != nullptr) DFS(node->left, curSum, targetSum, res);
    if (node->right != nullptr) DFS(node->right, curSum, targetSum, res);
}

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        bool res = false;
        DFS(root, 0, targetSum, res);
        return res;
    }
};