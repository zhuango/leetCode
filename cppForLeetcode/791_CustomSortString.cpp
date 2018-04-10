#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> mapping(26, 0);
        for (int i = 0; i < S.size(); ++i)
        {
            mapping[S[i]-'a'] = i + 1;
        }
        int pos = 0;
        int insertPos = 0;
        for(int i = 1; i < T.size(); ++i)
        {
            pos = mapping[T[i]-'a'];
            insertPos = i;
            if (pos == 0) continue;
            for(int j = i - 1; j >=0 ; --j)
            {
                if(mapping[T[j]-'a'] > pos)
                {
                    swap(T[j], T[insertPos]);
                    insertPos = j;
                }
            }
        }
        return T;
    }
};


int main(void)
{
    Solution sol;
    cout << sol.customSortString("kqep", "pekeq") << endl;
}