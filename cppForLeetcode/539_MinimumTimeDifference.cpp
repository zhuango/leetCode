#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for(auto s : timePoints)
        {
            minutes.push_back(str2minutes(s));
        }
        sort(minutes.begin(), minutes.end());
        int diff = minutes[1] - minutes[0];
        cout << diff << endl;
        for(int i = 2; i < timePoints.size(); ++i)
        {
            diff = min(diff, minutes[i] - minutes[i-1]);
        }
        diff = min(diff, minutes[0] + 24 * 60 - minutes.back());
        cout << diff << endl;
        return diff;
    }
    int str2minutes(string& str)
    {
        int hour = stoi(str.substr(0, 2));
        cout << hour << endl;
        int minutes = stoi(str.substr(3, 2));
        cout <<minutes << endl;
        return hour * 60 + minutes;
    }
};