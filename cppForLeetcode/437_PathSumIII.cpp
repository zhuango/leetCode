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
    int pathSum(TreeNode* root, int sum) {
        travEn(root, sum);
        return result;
    }
    void travEn(TreeNode *root, int sum)
    {
        if (root == NULL)
        {
            return;
        }
        trav(root, sum, 0);
        travEn(root->left, sum);
        travEn(root->right, sum);
    }
    void trav(TreeNode* root, int sum, int curSum)
    {
        if (root == NULL)
        {
            return;
        }
        curSum += root->val;
        if (curSum == sum)
        {
            result += 1;
        }
        
        trav(root->left, sum, curSum);
        trav(root->right, sum, curSum);
        curSum -= root->val;
    }
private:
    int result = 0;
};