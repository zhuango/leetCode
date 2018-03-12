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
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode * root, int key)
    {
        if (root == NULL)
        {
            return NULL;
        }
        
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if (root->val < key)
        {
            root->right= deleteNode(root->right, key);
            return root;
        }

        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        if (root->left == NULL && root->right != NULL)
        {
            TreeNode *right = root->right;
            delete root;
            return right;
        }
        if (root->left != NULL && root->right == NULL)
        {
            TreeNode *left = root->left;
            delete root;
            return left;
        }
        else
        {
            TreeNode *right = root->right;
            TreeNode *left  = root->left;
            delete root;

            TreeNode *preLeftest = right;
            TreeNode *leftest = right;
            while (leftest->left != NULL)
            {
                preLeftest = leftest;
                leftest = leftest->left;
            }
            root = leftest;
            preLeftest->left = leftest->right;
            if (leftest != right)
            {
                root->right = right;
            }
            else
            {
                root->right = leftest->right;
            }

            root->left = left;
            return root;
        }
    }
};