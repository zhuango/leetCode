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
        int index = 1;
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
            nodeIndex += 1;
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
    TreeNode *root = codec.deserialize("41 37 44 24 39 42 48 1 35 38 40 null 43 46 49 0 2 30 36 null null null null null null 45 47 null null null null null 4 29 32 null null null null null null 3 9 26 null 31 34 null null 7 11 25 27 null null 33 null 6 8 10 16 null null null 28 null null 5 null null null null null 15 19 null null null null 12 null 18 20 null 13 17 null null 22 null 14 null null 21 23");
    string s = codec.serialize(root);
    cout << s << endl;
}