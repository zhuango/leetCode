#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> temp_intervals;
        if (intervals.size() == 0) 
        {
            temp_intervals.push_back(newInterval);
            return temp_intervals;
        }
        temp_intervals.push_back({-2, -1});
        for (auto &interv : intervals)
        {
            temp_intervals.push_back(interv);
        }
        temp_intervals.push_back({100001, 100002});
        int index_s = find_interv(temp_intervals, newInterval[0]);
        int index_e = find_interv(temp_intervals, newInterval[1]);
        vector<vector<int>> results;
        
        bool in_out_s = newInterval[0] <= temp_intervals[index_s][1];
        bool in_out_e = newInterval[1] <= temp_intervals[index_e][1];
        
        for(int i = 0; i < temp_intervals.size() - 1; ++i)
        {
            if (i < index_s || i > index_e)
            {
                results.push_back(temp_intervals[i]);
            }
            if (i == index_s)
            {
                if (in_out_s && in_out_e)
                {
                    results.push_back({temp_intervals[index_s][0], temp_intervals[index_e][1]});
                    i = index_e;
                }
                if (in_out_s && (!in_out_e))
                {
                    results.push_back({temp_intervals[index_s][0], newInterval[1]});
                    i = index_e;
                }
                if ((!in_out_s) && (!in_out_e))
                {
                    results.push_back({temp_intervals[index_s][0], temp_intervals[index_s][1]});
                    results.push_back(newInterval);
                    i = index_e;
                }
                if((!in_out_s) && in_out_e)
                {
                    results.push_back({temp_intervals[index_s][0], temp_intervals[index_s][1]});
                    results.push_back({newInterval[0], temp_intervals[index_e][1]});
                    i = index_e;
                }
            }
        }
        return vector<vector<int>> (results.begin() + 1, results.end());
    }

    int find_interv(vector<vector<int>> & intervals, int n_se)
    {
        int start = 0;
        int end = intervals.size() - 1;
        while(end - start > 1)
        {
            int middle = (start + end) / 2;
            if (n_se < intervals[middle][0])
            {
                end = middle;
            }
            else
            {
                start = middle;
            }
        }
        return start;
    }
};

int main(void)
{
    Solution sol = Solution();
    vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};//{{1,3},{6,9}};
    vector<int> newInterval = {1, 11};//{2, 5};
    vector<vector<int>> res = sol.insert(intervals, newInterval);

    cout << "===========================" << endl;
    for(int i = 0; i < res.size(); ++i)
    {
        cout << res[i][0] << " " << res[i][1] << endl;
    }
}