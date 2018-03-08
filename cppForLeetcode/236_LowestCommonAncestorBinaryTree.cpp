// Definition for a binary tree node.
#include <iterator>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        has(root, p, q);
        return commonAncestor;
    }
    
private:
    bool has(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL) return false;
        if (commonAncestor != NULL) return true;
        bool hasInLeft = has(root->left, p, q);
        if (commonAncestor != NULL) return true;
        bool hasInRight = has(root->right, p, q);
        if (commonAncestor != NULL) return true;
        if (hasInLeft && hasInRight) 
        {
            commonAncestor = root;
            return true;
        }
        if ((root->val == p->val || root->val == q->val) && (hasInLeft || hasInRight))
        {
            commonAncestor = root;
            return true;
        }
        return hasInLeft || hasInRight || root->val == p->val || root->val == q->val;
    }
    TreeNode *commonAncestor = NULL;
};

int main(void)
{
    TreeNode root(10);
    root.left = new TreeNode(1);
    root.right = new TreeNode(2);
    root.right->left = new TreeNode(3);
    root.right->right = new TreeNode(4);
    root.right->right->right = new TreeNode(6);

    root.left->left = new TreeNode(5);
    Solution sol;
    cout << sol.lowestCommonAncestor(&root, root.right->right, root.right->right->right)->val << endl;
}