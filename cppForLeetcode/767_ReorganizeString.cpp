#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        map<char, int> mapping;
        for(char c : S)
        {
            mapping[c] ++;
        }
        priority_queue<pair<int, char>> pq;
        int cri = (s.size() + 1) / 2;
        for(auto &pair : mapping)
        {
            if (pair.second > cri) return "";
            pq.push({pair.second, pair.first});
        }
        string s;
        pair<int, char> prev = {0, ' '};
        while(!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            s.push_back(cur.first);
            cur.second --;
            if (prev.first > 0)
            {
                pq.emplace(prev);
            }
            prev = cur;
        }
        return s;
    }
};

int main(void)
{
    Solution sol;
    sol.reorganizeString("baa");
    sol.reorganizeString("baaa");
    sol.reorganizeString("bbbaaaaccc");
    sol.reorganizeString("bb");
    sol.reorganizeString("abbcccddddeeeeeffffff");
    sol.reorganizeString("abddeeeeeffffff");
    sol.reorganizeString("vvvlo");
}