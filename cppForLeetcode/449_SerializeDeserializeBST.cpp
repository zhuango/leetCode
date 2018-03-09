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
#include <string>
#include <sstream>
#include <queue>
#include <iostream>

using namespace std;

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
        string result = "";
        string temp = "";
        TreeNode *last = NULL;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curNode = q.front();
            q.pop();
            if (curNode == NULL)
            {
                result += "null ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                result += int2str(curNode->val) + " ";
                q.push(curNode->left);
                q.push(curNode->right);
                if (curNode->right != NULL)
                {
                    last = curNode->right;
                }
                else if (curNode->left != NULL)
                {
                    last = curNode->left;
                }
            }
            if (curNode == last)
            {
                break;
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        vector<string> strs;
        string str;
        while (ss >> str)
        {
            strs.push_back(str);
        }
        int index = 0;
        vector<TreeNode*> queue;
        queue.push_back(new TreeNode(str2int(strs[0])));
        int nodeIndex = 0;
        while (index < strs.size())
        {
            if (isdigit(strs[index][0]))
            {
                queue[nodeIndex]->left = new TreeNode(str2int(strs[index]));
                queue.push_back(queue[nodeIndex]->left);
            }
            if (index + 1 >= strs.size())
            {
                break;
            }
            index += 1;
            if (isdigit(strs[index][0]))
            {
                queue[nodeIndex]->right = new TreeNode(str2int(strs[index]));
                queue.push_back(queue[nodeIndex]->right);
            }
            index += 1;
        }
        return queue[0];
    }
private:
    int str2int(string str)
    {
        stringstream ss(str);
        int res;
        ss>>res;
        return res;
    }
    string int2str(int s)
    {
        stringstream ss;
        ss << s;
        return ss.str();
    }
};

// Your Codec object will be instantiated and called as such:
int main(void)
{
    Codec codec;
    TreeNode *root = codec.deserialize("1 2 3 4 null 5 ");
    string s = codec.serialize(root);
    cout << s << endl;
}