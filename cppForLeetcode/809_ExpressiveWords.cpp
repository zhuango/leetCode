#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution
{
  public:
    int expressiveWords(string S, vector<string> &words)
    {
        map<int, int> canbeExtended;
        int count = 1;
        for (int i = 1; i < S.size(); ++i)
        {
            if (S[i] == S[i - 1])
            {
                count += 1;
            }
            else
            {
                if (count >= 3)
                {
                    while (count > 0)
                    {
                        canbeExtended[i - count - 1] = 1;
                        count -= 1;
                    }
                }
                count = 1;
            }
        }
        if (count >= 3)
        {
            while (count > 0)
            {
                canbeExtended[S.size() - count - 1] = 1;
                count -= 1;
            }
        }
        char prev = ' ';
        count = 0;
        int j = 0;
        int i = 0;
        for (string &str : words)
        {
            prev = str[0];
            if (str[0] != S[0])
                continue;
            j = 1;
            i = 1;
            for (i = 1; i < S.size();)
            {
                if (j < str.size() && S[i] == str[j])
                {
                    prev = str[j];
                    i++;
                    j++;
                }
                else
                {
                    if (canbeExtended[i - 1] == 1 && prev == S[i])
                    {
                        i++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (j == str.size() && i == S.size())
            {
                count++;
            }
        }
        return count;
    }
};