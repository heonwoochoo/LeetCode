/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        queue<pair<Node*, int>> q;
        q.push({ root,0 });
        queue<Node*> nodes;
        int level = 0;
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            if (node.second > level)
            {
                level = node.second;
                nodes.pop();
            }

            nodes.push(node.first);

            if (nodes.size() > 1)
            {
                nodes.front()->next = nodes.back();
                nodes.pop();
            }
            if (node.first->left == nullptr && node.first->right == nullptr) continue;
            if (node.first->left != nullptr) q.push({node.first->left,node.second + 1});
            if (node.first->right != nullptr) q.push({ node.first->right,node.second + 1 });
        }

        return root;
    }
};