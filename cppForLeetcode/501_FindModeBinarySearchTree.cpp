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
        find(root, 0);
    }
    void find(TreeNode *root, int count)
    {
        if (count > max)
        {
            max = count;
        }
    }
    private:
        int max = 0;
        vector<int> set;
};