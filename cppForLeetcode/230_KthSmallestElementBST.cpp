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
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        vector<int> result;
        dfs(root, &result);
        return result[k-1];
    }
    void dfs(TreeNode* root, vector<int> *result)
    {
        if (root == NULL)
        {
            return;
        }
        if (result->size() == k)
        {
            return ;
        }
        dfs(root->left, result);
        if (result->size() == k)
        {
            return ;
        }
        result->push_back(root->val);
        dfs(root->right, result);
    }
private:
    int k = 0;
};