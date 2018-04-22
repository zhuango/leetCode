/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iterator>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_map<int, vector<int>> tag2Vec;
        unordered_map<int, int> mapping;
        
        for(int i = 0; i < G.size(); ++i)
        {
            tag2Vec[i + 1].push_back(G[i]);
            mapping[G[i]] = i + 1;
        }
        ListNode * prev = head;
        ListNode * cur = head->next;
        int mapping1 = 0;
        int mapping2 = 0;
        while(cur != NULL)
        {
            mapping1 = mapping[prev->val];
            mapping2 = mapping[cur->val];
            if(tag2Vec[mapping1].size() == 0 || tag2Vec[mapping2].size() == 0) 
            {
                prev = cur;
                cur = cur->next;
                continue;
            }
            if(tag2Vec[mapping1].size() > tag2Vec[mapping2].size())
            {
                for(int val : tag2Vec[mapping2])
                {
                    mapping[val] = mapping[prev->val];
                    tag2Vec[mapping1].push_back(val);
                }
                tag2Vec[mapping2].clear();
            }
            else
            {
                for(int val : tag2Vec[mapping1])
                {
                    mapping[val] = mapping[cur->val];
                    tag2Vec[mapping2].push_back(val);
                }
                tag2Vec[mapping1].clear();
            }
            prev = cur;
            cur = cur->next;
            cout << cur->val <<  " " << prev->next->val << endl;
        }
        int count;
        for(auto &v : tag2Vec)
        {
            if (v.second.size() != 0)
            {
                count += 1;
            }
        }
        return count;
    }
};

int main(void)
{
    Solution sol;
    ListNode *head = new ListNode(0);
    head->next = new ListNode(1);

    vector<int> input = {1};
    sol.numComponents(head, input);
}