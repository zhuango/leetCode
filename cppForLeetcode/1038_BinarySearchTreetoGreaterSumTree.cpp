#include <iterator>
#include <vector>
#include <unordered_map>

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
    void inTOrder(TreeNode* root, int &sum)
    {
        if(root == NULL) return ;
        inTOrder(root->right, sum);
        sum += root->val;
        root->val = sum;
        inTOrder(root->left, sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        inTOrder(root, sum);
        return root;
    }
    

};