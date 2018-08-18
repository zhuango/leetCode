#include <iterator>
#include <tuple>
#include <algorithm>

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
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        auto tu = findmax(root);
        return tu.second;
    }
    pair<int, int> findmax(TreeNode *root)
    {
        if(root == NULL) return {0, 0x80000000};
        auto leftTuple = findmax(root->left);
        auto rightTupl = findmax(root->right);
        int maxend = max(max(leftTuple.first, rightTupl.first) + root->val, root->val);
        int maxmid = max(root->val, leftTuple.first + rightTupl.first + root->val);
        int mm = max(max(maxend, maxmid), max(leftTuple.second, rightTupl.second));
        return {maxend, mm};
    }
};