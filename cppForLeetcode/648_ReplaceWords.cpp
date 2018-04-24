#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

class TrieTree
{
public:
    TrieTree ():c(' '), HasWords("") {}
    TrieTree (char cc): c(cc), HasWords("") {}
    char c;
    string HasWords;
    map<char, TrieTree *> children;
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        TrieTree root;
        for(string &str : dict)
        {
            insert(root, str);
        }
        string newSentence = "";
        stringstream ss(sentence);

        string s;
        while(!ss.eof())
        {
            ss >> s;
            string temp = searchPre(root, s);
            if(temp == "") newSentence += s + " ";
            else newSentence += temp + " ";
        }
        return newSentence.substr(0, newSentence.size() - 1);
    }
    void insert(TrieTree &root, string str)
    {
        TrieTree *index = &root;
        for(char c : str)
        {
            if(index->children.count(c) == 0)
            {
                TrieTree *node = new TrieTree(c);
                index->children[c] = node;
                index = node;
            }
            else
            {
                index = index->children[c];
            }
        }
        index->HasWords = str;
    }
    string searchPre(TrieTree &root, string &str)
    {
        TrieTree *index = &root;
        for(char c : str)
        {
            if(index->HasWords != "" || index->children.size() == 0)
            {
                return index->HasWords;
            }
            else if(index->children.count(c) == 0)
            {
                return "";
            }
            index = index->children[c];
        }
        return "";
    }
};

int main(void)
{
    // stringstream ss("liu zhuang is asdd");
    // string s;
    // while(!ss.eof())
    // {
    //     ss >> s;
    //     cout << s << endl;
    // }
    Solution sol;
    vector<string> input = {"a", "aa", "aaa", "aaaa"};
    cout << sol.replaceWords(input, "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa") << endl;
}