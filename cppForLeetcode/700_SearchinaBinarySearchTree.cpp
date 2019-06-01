
#include <iterator>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (NULL == root)
        {
            return NULL;
        }
        if (root->val == val)
        {
            return root;
        }
        TreeNode *newRoot = NULL;
        if (root->val > val)
        {
            newRoot = searchBST(root->left, val);
        }
        else
        {
            newRoot = searchBST(root->right, val);
        }

        return newRoot;
    }
};