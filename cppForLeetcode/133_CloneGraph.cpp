#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
//Definition for undirected graph.
 struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
  };

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        if(s[node->label] != NULL) return s[node->label];
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        s[newNode->label] = newNode;
        for(UndirectedGraphNode *neig : node->neighbors)
        {
            newNode->neighbors.push_back(cloneGraph(neig));
            //newNode->neighbors.back()->neighbors.push_back(newNode);
        }
        return newNode;
    }
    private:
    unordered_map<int, UndirectedGraphNode *> s;
};