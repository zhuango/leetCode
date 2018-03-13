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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        sum(root);
        return result;
    }
    void addToDict(int a)
    {
        if (sumCount.find(a) == sumCount.end())
        {
            sumCount[a] = 0;
        }
        sumCount[a] += 1;
        if (sumCount[a] > maxCount)
        {
            maxCount = sumCount[a];
            result.clear();
            result.push_back(a);
        }
        else if (sumCount[a] == maxCount)
        {
            result.push_back(a);
        }
    }
    int sum(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int sumLeft = sum(root->left);
        int sumRight= sum(root->right);
        int curSum = sumLeft + sumRight + root->val;
        addToDict(curSum);
        return curSum;
    }
    private:
        map<int, int> sumCount;
        int maxCount = 1;
        vector<int> result;
};