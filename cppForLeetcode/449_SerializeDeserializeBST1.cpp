#include <string>
#include <queue>
#include <sstream>
#include <vector>

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
    void seri(TreeNode *root, stringstream &ss)
    {
        if(root == NULL) return;
        ss << root->val << " ";
        seri(root->left, ss);
        seri(root->right, ss);
    }
    string serialize(TreeNode* root) {
        stringstream ss;
        seri(root, ss);
        string s = ss.str();
        while(s.back() == ' ') s.pop_back();

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        stringstream ss(data);
        string s;
        while(ss >> s)
        {
            nodes.push_back(s);
        }
        int pos = 0;
        return des(nodes, pos, 0x80000000, 0x7fffffff);
    }
    TreeNode *des(vector<string> &data, int &pos, int minv, int maxv)
    {
        if(pos >= data.size()) return NULL;
        int val = stoi(data[pos]);
        if(val < minv || val > maxv) return NULL;
        TreeNode *root = new TreeNode(val);
        pos ++;
        root->left = des(data, pos, minv, val);
        root->right = des(data, pos, val, maxv);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(