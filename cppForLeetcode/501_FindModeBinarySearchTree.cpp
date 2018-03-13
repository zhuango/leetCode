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
#include <map>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        find(root);
        return set;
    }
    void find(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        find(root->left);
        if (root->val != prev)
        {
            prev = root->val;
            curMax = 0;
        }
        curMax += 1;
        if (curMax > max)
        {
            max = curMax;
            set.clear();
            set.push_back(prev);
        }
        else if (curMax == max)
        {
            set.push_back(prev);
        }
        
        find(root->right);
    }
    private:
        int curMax = 0;
        int max = 0;
        int prev = 0;
        vector<int> set;
};