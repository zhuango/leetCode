#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

class Solution
{
  public:
    int numBusesToDestination(vector<vector<int>> &routes, int S, int T)
    {
        map<int, vector<int>> table;
        map<int, bool> visited;
        map<int, bool> stopV;
        queue<int> stops;
        queue<int> tempstops;
        for (int i = 0; i < routes.size(); ++i)
        {
            for (int n : routes[i])
            {
                table[n].push_back(i);
            }
        }
        int step = 1;
        int s = S;
        stops.push(S);
        bool stepSet = false;
        while (true)
        {
            stepSet = false;
            while (!stops.empty())
            {
                s = stops.front();
                stops.pop();
                stopV[s] = true;

                for (int bus : table[s])
                {
                    if (visited[bus]) continue;
                    visited[bus] = true;
                    for (int stop : routes[bus])
                    {
                        if (stopV[stop]) continue;
                        else stepSet = true;
                        tempstops.push(stop);
                        stopV[stop] = true;
                        if (stop == T)
                        {
                            return step;
                        }
                    }
                }
            }
            if (stepSet) step ++;
            stops.swap(tempstops);
            if (stops.empty())
                return -1;
        }
    }
};
int main(void)
{
    vector<vector<int>> input = {{0, 1, 6, 16, 22, 23}, {14, 15, 24, 32}, {4, 10, 12, 20, 24, 28, 33}, {1, 10, 11, 19, 27, 33}, {11, 23, 25, 28}, {15, 20, 21, 23, 29}, {29}};
    Solution sol;
    cout << sol.numBusesToDestination(input, 4, 21) << endl;
    input = {{1, 2, 7}, {3, 6, 7}};
    cout << sol.numBusesToDestination(input, 2, 6) << endl;
    input = {{7,12},{4,5,15},{6},{15,19},{9,12,13}};
    cout << sol.numBusesToDestination(input, 7, 12) << endl;

}