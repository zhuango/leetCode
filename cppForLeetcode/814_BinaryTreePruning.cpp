/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iterator>
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        bool hasone = hasOnes(root);
        if (hasone) return root;
        else return NULL;
    }
    bool hasOnes(TreeNode *root)
    {
        if(root == NULL) return false;
        bool left = hasOnes(root->left);
        if (!left) root->left = NULL;
        bool right = hasOnes(root->right);
        if(!right) root->right = NULL;
        if (left || right || root->val == 1)
        {
            return true;
        }
        else return false;
    }
};