#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
               int sum = 0, len = A.size();
        for(int i = 0; i < A.size(); i++) {
            sum += A[i];
        }
        
        double aver = sum / (double)len;
        
        for(int i = 1; i <= len / 2; i++) {
            if(sum * i % len != 0)
                continue;
            
            if(checkSum(A, sum * i / len, i, 0, 0, 0))
                return true;
        }
        
        return false;
    }
    bool checkSum(vector<int> &A, int sum, int num, int start, int curSum, int curCount) {
        if(curCount == num && sum == curSum)
            return true;
        if(curCount == num)
            return false;
        
        for(int i = start; i < A.size(); i++) {
            if(curSum + A[i] <= sum) {
                if(checkSum(A, sum, num, i + 1, curSum + A[i], curCount + 1))
                    return true;
            }
        }
        
        return false;
    }
};