#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> result(A.size(), 0);
        vector<bool> notset(A.size(), true);
        vector<int> rest;

        for(int i = 0; i < A.size(); ++i)
        {
            int temp = 0x7fffffff;
            int tar = -1;
            for(int j = 0; j < B.size(); ++j)
            {
                if(notset[j] && A[i] > B[j] && A[i] - B[j] < temp)
                {
                    tar = j;
                    temp = A[i] - B[j];
                }
            }
            if(tar != -1)
            {
                result[tar] = A[i];
                notset[tar] = false;
            }
            else rest.push_back(A[i]);
        }
        int i = 0;
        int j = 0;
        for(int j = 0; j < A.size(); ++j)
        {
            if(notset[j])
            {
                result[j] = rest[i];
                i++;
            }
        }
        return result;
    }
};

int main(void)
{
    vector<int> a = {5621,1743,5532,3549,9581};
    vector<int> b = {913,9787,4121,5039,1481};
    Solution sol;
    for(int i : sol.advantageCount(a, b))
    {
        cout << i << " " ;
    }
    cout << endl;

    return 0;
}