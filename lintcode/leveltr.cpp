#include <vector>
#include <queue>
#include <iterator>
#include <map>

using namespace std;
// Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};


class Solution {
public:
    /**
    @param root: A Tree
    @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        vector<int> level;
        int curLev = 1;
        while(!q.empty())
        {
            pair<TreeNode*, int> curNode = q.front();
            q.pop();
            if(curNode.second == curLev)
            {
                level.push_back(curNode.first->val);
            }
            else
            {
                result.push_back(level);
                level.clear();
                level.push_back(curNode.first->val);
                curLev ++;
            }
            if(curNode.first->left != NULL) q.push({curNode.first->left, curLev + 1});
            if(curNode.first->right != NULL) q.push({curNode.first->right, curLev + 1});
        }
        if(level.size() != 0) result.push_back(level);
        return result;
    }
};