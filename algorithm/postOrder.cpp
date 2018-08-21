#include <iterator>
#include <algorithm>
#include <stack>
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> st;
        
        TreeNode *index = root;
        
        while(!st.empty()||index != NULL)
        {
            if(index != NULL)
            {
                st.push(index);
                result.push_back(index->val);
                index = index->right;
            }
            else
            {
                TreeNode *n = st.top();
                st.pop();
                index = n->left;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};