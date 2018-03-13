#include <iterator>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxLength;
    }
    int dfs(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return 0;
        }

        int curLength = 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if (root->left != NULL) curLength += left + 1;
        if (root->right != NULL) curLength += right + 1;
        if (curLength > maxLength)
        {
            maxLength = curLength;
        }

        if (left > right)
        {
            return left + 1;
        }
        else
        {
            return right + 1;
        }
    }
    private:
    int maxLength = 0;
};