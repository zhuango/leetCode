#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL)
        {
            return 0;
        }
        if(root->children.size() == 0)
        {
            return 1;
        }
        int maxHigh = 0;
        for(int i = 0; i < root->children.size(); ++i)
        {
            int temp = maxDepth(root->children[i]);
            if(temp > maxHigh)
            {
                maxHigh = temp;
            }
        }
        return maxHigh + 1;
    }
};