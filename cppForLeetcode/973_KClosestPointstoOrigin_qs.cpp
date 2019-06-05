#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comer(vector<int> &p1, vector<int> &p2)
{
    return p1[0] * p1[0] + p1[1] * p1[1] >= p2[0] * p2[0] + p2[1] * p2[1];
}

class Solution {
public:
    int divideAndConquer(vector<vector<int>> &points, int l, int r)
    {
        vector<int> pivot = points[l];
        while(l < r)
        {
            while(l < r && comer(points[r], pivot)) r--;
            points[l] = points[r];
            while(l < r && comer(pivot, points[l])) l++;
            points[r] = points[l];
        }
        points[l] = pivot;
        return l;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int l = 0, r = points.size() - 1;
        int mid = 0;
        while(l < r)
        {
            mid = divideAndConquer(points, l, r);
            if (mid == K) break;
            if (mid < K)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return vector<vector<int>> (points.begin(), points.begin() + K);
    }
};

int main(void)
{
    Solution sol;
    vector<vector<int>> input = {{0,1},{1,0}};
    for(auto &vec: sol.kClosest(input, 2))
    {
        for(int i : vec)
        {
            cout << i << " " ;
        }
        cout << endl;
    }
}