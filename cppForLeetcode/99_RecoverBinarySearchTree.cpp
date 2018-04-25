#include <iterator>
#include <map>
using namespace std;

// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(0x80000000);
        dfs(root);
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }
    void dfs(TreeNode *root)
    {
        if(root == NULL) return;
        dfs(root->left);
        if(node1 == NULL && root->val <= prev->val)
        {
            node1 = prev;
        }
        if(node1 != NULL && root->val <= prev->val)
        {
            node2 = root;
        }
        prev = root;
        dfs(root->right);
    }

    private:
    TreeNode *prev = NULL;
    TreeNode *node1 = NULL;
    TreeNode *node2 = NULL;
};