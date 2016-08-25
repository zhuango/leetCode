#!/usr/bin/python3
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0
        table = [0 for i in range(n + 2)]
        table[0] = 0
        table[1] = nums[0]
        i = 1
        while i < n:
            table[i + 1] = max(nums[i] + table[i - 1], table[i])
            i += 1
        return table[n]
sol = Solution()
print(sol.rob([]))
print(sol.rob([1, 2, 3, 4, 5, 6, 7, 8, 9]))
print(sol.rob([1, 23, 324, 1232, 2, 2, 3, 2, 3]))