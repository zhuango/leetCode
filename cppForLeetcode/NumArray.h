#include"Common.h"

class NumArray {
public:
    NumArray(vector<int> &nums) {
        mNums = nums;
        int temp = 0;
        mark.reset(new int[nums.size()]);
        for (int i = 0; i < nums.size(); ++i)
        {
            temp += nums[i];
            mark.get()[i] = temp;
        }
    }

    int sumRange(int i, int j) {
        return mark.get()[j] - mark.get()[i] + mNums[i];
    }
private:
    inline int Tran(int i, int j)
    {
        if (i < 0) return 0;
        return i * mNums.size() + j;
    }
    vector<int> mNums;
    shared_ptr<int> mark;
};