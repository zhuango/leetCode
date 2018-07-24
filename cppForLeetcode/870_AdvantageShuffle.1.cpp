#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<pair<int, int>> sortedB;
        for(int i = 0; i < B.size(); ++i)
        {
            sortedB.push_back({B[i], i});
        }
        sort(sortedB.begin(), sortedB.end());
        sort(A.begin(), A.end());
        
        vector<int> result(A.size(), 0);
        vector<bool> notset(A.size(), true);
        vector<int> rest;

        int j = 0;
        for(int i = 0; i < A.size(); ++i)
        {
            if(j < B.size() && A[i] > sortedB[j].first)
            {
                result[sortedB[j].second] = A[i];
                notset[sortedB[j].second] = false;
                j += 1;
            }
            else rest.push_back(A[i]);
        }
        int i = 0;
        while(j < A.size())
        {
            if(notset[sortedB[j].second])
            {
                result[sortedB[j].second] = rest[i];
                i++;
            }
            j += 1;
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