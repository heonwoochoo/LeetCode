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
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        stack<pair<TreeNode*,int>> st;
        unordered_set<TreeNode*> mp;
        st.push({ root, 0 });

        int maxLevel = 0;
        int res = 0;

        while (!st.empty())
        {
            pair<TreeNode*,int> cur = st.top();
            st.pop();
            if (mp.find(cur.first) != mp.end())
            {
                continue;
            }
            else
            {
                mp.insert(cur.first);
                if (maxLevel == cur.second)
                {
                    res += cur.first->val;
                }
                else if (maxLevel < cur.second)
                {
                    maxLevel = cur.second;
                    res = cur.first->val;
                }

                if (cur.first->right != nullptr)
                {
                    st.push({ cur.first->right, cur.second + 1 });
                }
                if (cur.first->left != nullptr)
                {
                    st.push({ cur.first->left, cur.second + 1 });
                }
            }
        }
        return res;
    }
};