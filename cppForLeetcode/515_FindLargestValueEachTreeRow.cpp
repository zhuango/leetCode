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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (root == NULL)
        {
            return result;
        }
        vector<int> queueLevel =  {0};
        vector<TreeNode *> queueNode = {root};
        int index = 0;
        int max = root->val;
        int prelevel = 0;
        while (index < queueLevel.size())
        {
            TreeNode *curNode = queueNode[index];
            if (queueLevel[index] != prelevel)
            {
                result.push_back(max);
                prelevel = queueLevel[index];
                max = curNode->val;
            }
            else
            {
                if (curNode->val > max)
                {
                    max = curNode->val;
                }
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
        result.push_back(max);
        return result;
    }
};