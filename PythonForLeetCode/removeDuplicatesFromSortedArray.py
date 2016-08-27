#!/usr/bin/python3
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0
        curIndex = 0
        i = 1
        while i < n:
            if not nums[i] == nums[curIndex]:
                curIndex += 1
                nums[curIndex] = nums[i]
            i += 1
        return curIndex + 1
array = [1, 1, 2]
sol = Solution()
print(sol.removeDuplicates(array))

print(sol.removeDuplicates([1, 1, 2]))
print(sol.removeDuplicates([1, 2]))
print(sol.removeDuplicates([1]))
print(sol.removeDuplicates([]))