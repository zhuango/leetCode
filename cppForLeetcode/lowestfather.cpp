#include "Common.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v):val(v), left(NULL), right(NULL){}
};

TreeNode *CreateTree(vector<int> &preorder, int &start)
{
    TreeNode *root = NULL;
    if(start < preorder.size() && preorder[start] != -1)
    {
        root = new TreeNode(preorder[start]);
        start ++;
        root->left = CreateTree(preorder, start);
        start ++;
        root->right = CreateTree(preorder, start);
    }
    return root;
}

void preorderPrint(TreeNode *root)
{
    if(root != NULL)
    {
        cout << root->val << " ";
        preorderPrint(root->left);
        preorderPrint(root->right);
    }
    else
    {
        cout << "-1 " ;
    }
}

    void myfind(TreeNode *root, TreeNode *p, TreeNode *q, vector<TreeNode*> &pathp, vector<TreeNode*> &pathq)
    {
        if(root!= NULL)
        {
            if(pathq.size() == 0 || pathq[pathq.size() - 1] != q) pathq.push_back(root);
            if(pathp.size() == 0 || pathp[pathp.size() - 1] != p) pathp.push_back(root);
            if(pathp[pathp.size() - 1] == p && pathq[pathq.size() - 1] == q)
            {
                return ;
            }
            else
            {
                myfind(root->right, p, q, pathp, pathq);
                myfind(root->left, p, q, pathp, pathq);
                if(pathq[pathq.size() - 1] != q) pathq.erase(pathq.end() - 1);
                if(pathp[pathp.size() - 1] != p) pathp.erase(pathp.end() - 1);
            }
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathp;
        vector<TreeNode*> pathq;
        myfind(root, p, q, pathp, pathq);
        int i = 0;
        cout << "########################" <<endl;
        for(auto iter = pathp.begin(); iter != pathp.end(); ++iter)
        {
            cout << (*iter)->val << " " ;
        }
        cout << endl;
        cout << "########################" <<endl;
        for(auto iter = pathq.begin(); iter != pathq.end(); ++iter)
        {
            cout << (*iter)->val << " " ;
        }
        cout << endl;
        cout << "########################" <<endl;
        while(i < min(pathp.size(), pathq.size()) && pathp[i] == pathq[i])
        {
            ++i;
        }
        return pathp[i-1];
    }
    

int main(void)
{
    vector<int> array = {1, 2, -1, 3, 4,5, -1, 6};
    int result = 0;
    TreeNode *root = CreateTree(array, result);
    preorderPrint(root);
    cout << endl;
    TreeNode *commonRoot = lowestCommonAncestor(root, root->left->right, root->left->left);
    cout << commonRoot->val << endl;
}
