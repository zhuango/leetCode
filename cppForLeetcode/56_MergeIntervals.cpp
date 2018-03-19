/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> results;
        if (intervals.empty()) return results;
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){
            if (a.start != b.start)
            {
                return a.start < b.start;
            }
            else
            {
                return a.end < b.end;
            }
        });
        results.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i].start <= results.back().end)
            {
                results.back().end = max(results.back().end, intervals[i].end);
            }
            else
            {
                results.push_back(intervals[i]);
            }
        }
        return results;
    }
};