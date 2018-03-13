/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <tuple>
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
    int findBottomLeftValue(TreeNode* root) {
        vector<int> queueLevel =  {0};
        vector<TreeNode *> queueNode = {root};
        int index = 0;
        TreeNode *first = root;
        int prelevel = 0;
        while (index < queueLevel.size())
        {
            TreeNode *curNode = queueNode[index];
            if (queueLevel[index] != prelevel)
            {
                prelevel = queueLevel[index];
                first = curNode;
            }
            if (curNode == NULL)
            {
                continue;
            }
            if (curNode->left != NULL)
            {
                queueNode.push_back(curNode->left);
                queueLevel.push_back(queueLevel[index] + 1);
            }
            if (curNode->right != NULL)
            {
                queueNode.push_back(curNode->right);
                queueLevel.push_back(queueLevel[index] + 1);
            }
            index += 1;
        }
        return first->val;
    }
};

int main()
{

}