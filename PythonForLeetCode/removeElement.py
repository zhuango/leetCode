#!/usr/bin/python3
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        n = len(nums)
        counter = 0
        i = n - 1
        while i >= 0:
            if nums[i] == val:
                temp = nums[n - 1 - counter]
                nums[n - 1 - counter] = nums[i]
                nums[i] = temp
                counter += 1
            i-= 1
        return n - counter

sol = Solution()
print(sol.removeElement([1, 2, 3, 4, 4, 5, 6, 7], 4))