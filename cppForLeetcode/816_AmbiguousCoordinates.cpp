#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> results;
        string result;
        S = S.substr(1, S.size() - 2);
        for(int i = 1; i < S.size(); ++i)
        {
            string sLeft = S.substr(0, i);
            if (!valid(sLeft)) continue;
            string sRight = S.substr(i);
            if (!valid(sRight)) continue;
            
            for(int k = 0; k < sLeft.size(); ++k)
            {
                if(sLeft[0] == '0')
                {
                    if(k > 0) break;
                    if (sLeft.size() > 1) result = "(" + sLeft.substr(0, 1) + "." + sLeft.substr(1) + ", ";
                    else result = "(" + sLeft + ", ";
                }
                else
                {
                    if (k && sLeft.back() != '0') result = "(" + sLeft.substr(0, k) + "." + sLeft.substr(k) + ", ";
                    else if(k < 1) result = "(" + sLeft + ", ";
                    else break;
                }

                for(int m = 0; m < sRight.size(); ++m)
                {
                    if(sRight[0] == '0')
                    {
                        if(m > 0) break;
                        if (sRight.size() > 1) results.push_back(result + sRight.substr(0, 1) + "." + sRight.substr(1) + ")");
                        else results.push_back(result + sRight + ")");
                    }
                    else
                    {
                        if (m && sRight.back() != '0') results.push_back(result + sRight.substr(0, m) + "." + sRight.substr(m) +")");
                        else if(m < 1) results.push_back(result + sRight + ")");
                        else break;
                    }
                }
            }
        }
        return results;
    }
    bool valid(string s)
    {
        if (s.size() == 1) return true;
        if (s[0] == '0' && s.back() == '0') return false;
        return true;
    }
};