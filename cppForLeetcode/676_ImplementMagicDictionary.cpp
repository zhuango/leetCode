#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class TrieTree
{
    public:
    TrieTree(){}
    TrieTree(char cc) : c(cc){}
    char c;
    bool hasWord = false;
    unordered_map<char, TrieTree*> children;
};

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        if (root.children.size() != 0)
        {
            return ;
        }
        for(string &s : dict)
        {
            insert(s);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        bool notsame = true;
        TrieTree *index = &root;
        int i = 0;
        bool result = false;
        // for(auto &pair : index->children)
        // {
        //     if(pair.first == c) continue;
        //     result |= simpleSearch(pair.second, word.substr(i + 1));
        // }
        for(i = 0; i < word.size(); ++i)
        {
            char c = word[i];
            for(auto &pair : index->children)
            {
                if(pair.first == c) continue;
                result |= simpleSearch(pair.second, word.substr(i + 1));
            }
            if(result) return true;
            if(index->children.count(c) != 0)
            {
                index = index->children[c];
            }
            else
            {
                return result;
            }
        }
        return result;
    }
    private:
    TrieTree root;

    void insert(string s)
    {
        TrieTree *index = &root;
        for(char c : s)
        {
            if(index->children.count(c) != 0)
            {
                index = index->children[c];
            }
            else
            {
                TrieTree *node = new TrieTree(c);
                index->children[c] = node;
                index = node;
            }
        }
        index->hasWord = true;
    }
    bool simpleSearch(TrieTree *root, string s)
    {
        TrieTree *index = root;
        for(char c : s)
        {
            if(index->children.count(c) != 0)
            {
                index = index->children[c];
            }
            else
            {
                return false;
            }
        }
        if(index->hasWord) return true;
        else return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */

int main(void)
{
    vector<string> input = {"h", "hhllo", "leetcode"};
    MagicDictionary m;
    m.buildDict(input);
    cout << m.search("a") << endl;

    return 0;
}