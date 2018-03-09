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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return trav(nums, 0, nums.size()-1);
    }
    TreeNode* trav(vector<int>& nums, int start, int end)
    {
        if (start > end) return NULL;
        if (start == end)
        {
            return new TreeNode(nums[start]);
        }
        int middle = start + (end - start) / 2;
        TreeNode * root = new TreeNode(nums[middle]);
        root->left = trav(nums, start, middle - 1);
        root->right = trav(nums, middle + 1, end);
        return root;
    }
};
// 1, 2, 3, 4, 5, 6, 7, 8