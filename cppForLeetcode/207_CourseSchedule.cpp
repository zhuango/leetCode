#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(prerequisites.empty()) return true;
        unordered_map<int, vector<int>> mapping;
        for(auto &pair : prerequisites)
        {
            mapping[pair.first].push_back(pair.second);
        }
        for(int i = 0; i < numCourses; ++i)
        {
            visited[i] = false;
            tag[i] = false;
        }
        for(int i = 0; i < numCourses; ++i)
        {
            if (dfs(mapping, i))
            {
                return false;
            }
        }
        return true;
    }
    bool dfs(unordered_map<int, vector<int>> &mapping, int course)
    {
        if(tag[course]) return false;
        if(visited[course]) return true;
        visited[course] = true;
        for(int nextCounrse : mapping[course])
        {
            if(dfs(mapping, nextCounrse))
            {
                return true;
            }
            tag[nextCounrse] = true;
        }
        tag[course] = true;
        visited[course] = false;
        return false;
    }
    private:
    unordered_map<int, bool> visited;
    unordered_map<int, bool> tag;
    bool hasLoop = false;
};

int main(void)
{
    Solution sol;
    vector<pair<int, int>> input = {{0, 1}, {0, 2}, {1, 2}};
    cout << sol.canFinish(3, input) << endl;
    return 0;
}