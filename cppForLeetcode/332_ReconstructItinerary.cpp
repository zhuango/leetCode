#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <set>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for (auto ticket : tickets)
            targets[ticket.first].insert(ticket.second);
        visit("JFK");
        return vector<string>(route.rbegin(), route.rend());
    }

    map<string, multiset<string>> targets;
    vector<string> route;

    void visit(string airport) {
        cout << airport << endl;
        while (targets[airport].size()) {
            string next = *targets[airport].begin();
            // Erase the tickets that would be recored.
            // To keep no loop.
            targets[airport].erase(targets[airport].begin());
            visit(next);
        }
        // If JFK has many destinations.
        // We can reach the end of itinerary starting with any one of them.
        route.push_back(airport);
    }
};

int main(void)
{
    Solution sol;
    vector<pair<string, string>> input = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    for(string &s : sol.findItinerary(input))
    {
        //cout << s << endl;
    }
    return 0;
}
// [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]