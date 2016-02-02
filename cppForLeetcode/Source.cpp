#include "BulbSwitcher.h"
#include "LongestIncreasingPath.h"
#include "OddEvenLinkedList.h"
#include "NumArray.h"


void main(void)
{
    vector<int> test(10, 1);
    NumArray array(test);
    cout << array.sumRange(0, 1) << endl;
    cout << array.sumRange(0, 5) << endl;
}