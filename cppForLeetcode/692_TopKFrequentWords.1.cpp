#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution { 
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for(string s : words) { 
            auto it = count.find(s);
            if(it == count.end()) { 
                count.insert(make_pair(s, 1));
            } else { 
                it->second += 1;
            }
        }
        auto comp = [&](const pair<string,int>& a, const pair<string,int>& b) {
            return a.second < b.second || (a.second == b.second && a.first > b.first);
        };
        typedef priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq_t;
        pq_t pq(comp);
        for (auto p : count) { 
            pq.emplace(p.first, p.second);
        }
        
        vector<string> sol;
        for(int i = 0; i <k; i++) { 
            sol.push_back(pq.top().first);
            pq.pop();
        }
        return sol;
    }
};

int main(void)
{
    Solution sol;
    vector<string> input = {"i", "love", "leetcode", "i", "love", "coding"};
    for (auto &str : sol.topKFrequent(input, 2))
    {
        cout << str << endl;
    }
}