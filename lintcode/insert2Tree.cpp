#include <iterator>

using namespace std;

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
    /*
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode * insertNode(TreeNode * root, TreeNode * node) {
        // write your code here
        if(root == NULL) return node;
        TreeNode * index = root;
        TreeNode * parent = root;
        
        while(index != NULL)
        {
            parent = index;
            if(index->val > node->val) index = index->left;
            else index = index->right;
        }
        if(node->val > parent->val) parent->right = node;
        else parent->left = node;
        return root;
    }
};