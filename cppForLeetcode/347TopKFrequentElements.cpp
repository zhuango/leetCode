#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mapping;
        unordered_map<int, vector<int>> niMapping;
        for(int i : nums)
        {
            mapping[i] += 1;
        }
        for(auto &pair : mapping)
        {
            niMapping[pair.second].push_back(pair.first);
        }
        priority_queue<int> pq;
        for(auto &pair : niMapping)
        {
            pq.push(pair.first);
        }
        vector<int> results;
        while(k != 0)
        {
            for(int i : niMapping[pq.top()]) 
            {
                results.push_back(i);
                k -= 1;
                if(k == 0) break;
            }
            pq.pop();
            
        }
        return results;
    }
};

int main(void)
{
    vector<int> input = {1,2};
    Solution sol;
    for(int i : sol.topKFrequent(input, 2))
    {
        cout << i << endl;
    }
}