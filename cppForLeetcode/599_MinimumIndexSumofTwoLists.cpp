#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> results;
        unordered_map<string, int> mapping;
        int i = 0;
        for(string &s : list1)
        {
            mapping[s] = i;
            i += 1;
        }
        int i = 0;
        int mi = list1.size() + list2.size();
        for(string &s : list2)
        {
            if(mapping.count(s) > 0)
            {
                int temp  = i + mapping[s];
                if (temp == mi)
                {
                    results.push_back(s);
                }
                else if(temp < mi)
                {
                    mi = temp;
                    results.clear();
                    results.push_back(s);
                }
            }
        }
        return results;
    }
};