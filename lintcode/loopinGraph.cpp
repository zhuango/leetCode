#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    /**
     * @param start: The start points set
     * @param end: The end points set
     * @return: Return if the graph is cyclic
     */
    bool isCyclicGraph(vector<int> &start, vector<int> &end) {
        // Write your code here
        map<int, vector<int>> mapping;
        map<int, int> in;
        queue<int> mp;
        
        for(int i = 0; i < end.size(); ++i)
        {
            mapping[start[i]].push_back(end[i]);
            if(in.count(start[i]) == 0)
            {
                in[start[i]] = 0;
            }
            in[end[i]] ++ ;
        }
        
        for(auto &p : in)
        {
            if(p.second == 0)
            {
                mp.push(p.first);
            }
        }
        while(!mp.empty())
        {
            int curN = mp.front();
            mp.pop();
            in.erase(curN);
            for(int i : mapping[curN])
            {
                in[i] -= 1;
                if(in[i] == 0)
                {
                    mp.push(i);
                }
            }
        }
        if(in.size() == 0) return false;
        else return true;
    }
};