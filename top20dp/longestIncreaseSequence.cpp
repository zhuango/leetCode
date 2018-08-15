#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
	/**
	* @param nums: An integer array
	* @return: The length of LIS (longest increasing subsequence)
	*/
	int longestIncreasingSubsequence(vector<int> &nums) {
		// write your code here
		if (nums.size() == 0) return 0;
		vector<int> length(nums.size(), 0);
		length[0] = 1;
		int result = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			int mm = 1;
			for (int j = 0; j < i; ++j)
			{
				if (nums[i] > nums[j])
				{
					mm = max(mm, length[j] + 1);
				}
			}
			length[i] = mm;
			if (length[i] > result)
			{
				result = length[i];
			}
		}
		return result;
	}
};

int main(void)
{
	Solution sol;
	vector<int> input = { 5,4, 1, 2, 3 };
	sol.longestIncreasingSubsequence(input);
}