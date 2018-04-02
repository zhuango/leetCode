#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int countG = 0;
        int countL = 0;
        int maxN = A.size();
        map<int, int> mapping;
        mapping[-1] = 0;
        for (int i = 1; i < A.size(); ++i)
        {
            if (abs(A[i] - i) >= 2) return false;
        }
        return countG == countL;
    }
};