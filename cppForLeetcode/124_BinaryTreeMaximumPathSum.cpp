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
        return get<1>(tu);
    }
    tuple<int, int> findmax(TreeNode *root)
    {
        if(root == NULL) return {0, 0x80000000};
        auto leftTuple = findmax(root->left);
        auto rightTupl = findmax(root->right);
        int maxend = max(max(get<0>(leftTuple), get<0>(rightTupl)) + root->val, root->val);
        int maxmid = max(root->val, get<0>(leftTuple) + get<0>(rightTupl) + root->val);
        int mm = max(max(maxend, maxmid), max(get<1>(leftTuple), get<1>(rightTupl)));
        return {maxend, mm};
    }
};