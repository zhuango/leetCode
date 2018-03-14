#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int columnStart = 0;
        int columnEnd = n;

        int rowStart = 0;
        int rowEnd = n;
        
        int num = 1;
        int i = 0;
        while (columnStart < columnEnd || rowStart < rowEnd)
        {
            if (columnStart < columnEnd)
            {
                for (i = columnStart; i < columnEnd; ++i)
                {
                    result[rowStart][i] = num;
                    num += 1;
                }
                rowStart += 1;
            }
            else break;
            if (rowStart < rowEnd)
            {
                for (i = rowStart; i < rowEnd; ++i)
                {
                    result[i][columnEnd - 1] = num;
                    num += 1;
                }
                columnEnd -= 1;
            }
            else break;
            if (columnStart < columnEnd)
            {
                for (i = columnEnd - 1; i >= columnStart; --i)
                {
                    result[rowEnd-1][i] = num;
                    num +=1;
                }
                rowEnd -= 1;
            }
            else break;
            if (rowStart < rowEnd)
            {
                for (i = rowEnd - 1; i >= rowStart; --i)
                {
                    result[i][columnStart] = num;
                    num += 1;
                }
                columnStart += 1;
            }
            else break;
        }
        return result;
    }
};

int main(void)
{
    Solution sol;
    auto result = sol.generateMatrix(5);
    for(auto vec: result)
    {
        for(int a: vec)
        {
            cout << a << " ";
        }
        cout << endl;
    }
}