#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class CTree
{
    public:
    CTree(char c) : data(c){}
    char data;
    unordered_map<char, CTree*> children;
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        CTree root('*');
        for(int i = 0; i < words.size(); ++i)
        {
            insert(&root, words[i], words[i].size() - 1);
        }
        auto result = countLeaf(root);
        return result.first;
    }
    void insert(CTree *root, string &s,int index)
    {
        if(index < 0) return;
        char tempC = s[index];
        if(root->children.count(tempC) == 0)
        {
            CTree *newNode = new CTree(tempC);
            root->children[tempC] = newNode;
        }
        insert(root->children[tempC], s, index - 1);
    }
    pair<int, int> countLeaf(CTree &root)
    {
        if(root.children.size() == 0)
        {
            return {1, 1};
        }
        int count = 0;
        int path = 0;
        for(auto &pair : root.children)
        {
            auto p = countLeaf(*(pair.second));
            count += p.first;
            path += p.second;
        }
        return {count + path, path};
    }
};

int main(void)
{
    vector<string> input = {"time", "me", "bell"};
    Solution sol;
    cout << sol.minimumLengthEncoding(input) << endl;
}