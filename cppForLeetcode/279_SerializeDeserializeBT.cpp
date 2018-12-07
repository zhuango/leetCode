#include <string>
#include <queue>
#include <sstream>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> nodes;
        nodes.push(root);
        stringstream ss;
        while(!nodes.empty())
        {
            TreeNode *curNode = nodes.front();
            nodes.pop();
            if(curNode == NULL) ss << "# ";
            else ss << curNode->val << " ";

            if(curNode)
            {
                nodes.push(curNode->left);
                nodes.push(curNode->right);
            }
        }
        string result = ss.str();
        while(result != "" && (result.back() == '#' || result.back() == ' ')) result.pop_back();
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string s;
        ss >> s;
        if(s == "" || s == "#") return NULL;
        TreeNode *root = new TreeNode(stoi(s));
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *r = q.front();
            q.pop();
            if(!(ss >> s)) break;
            if(s != "#")
            {
                r->left = new TreeNode(stoi(s));
                q.push(r->left);
            }

            if(!(ss >> s)) break;
            if(s != "#")
            {
                r->right = new TreeNode(stoi(s));
                q.push(r->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(