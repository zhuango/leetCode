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
    TreeNode* convertBST(TreeNode* root) {
        postOrder(root);
        return root;
    }
    void postOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return ;
        }
        postOrder(root->right);
        sum += root->val;
        root->val = sum;
        postOrder(root->left);
    }
    private:
    int sum = 0;
};