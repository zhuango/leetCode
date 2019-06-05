#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> kClosestPoints(points.begin(), points.begin() + K);
        auto comer = [](vector<int> &p, vector<int> &p1) {return p[0] * p[0] + p[1] * p[1] <= p1[0] * p1[0] + p1[1] * p1[1];};

        make_heap(kClosestPoints.begin(), kClosestPoints.end(), comer);
        for(int i = K; i < points.size(); ++i)
        {
            if (comer(kClosestPoints[0], points[i]))
            {
                continue;
            }
            kClosestPoints.push_back(points[i]);
            push_heap(kClosestPoints.begin(), kClosestPoints.end(), comer);
            pop_heap(kClosestPoints.begin(), kClosestPoints.end(), comer);
            kClosestPoints.pop_back();
        }
        return kClosestPoints;
    }
};

int main(void)
{
    Solution sol;
    vector<vector<int>> input = {{3,3},{5,-1},{-2,4}};
    for(auto &vec: sol.kClosest(input, 2))
    {
        for(int i : vec)
        {
            cout << i << " " ;
        }
        cout << endl;
    }
}