#!/usr/bin/python3
class Solution(object):
    def swap(self, nums, start, end):
        while start < end:
            temp = nums[start]
            nums[start] = nums[end]
            nums[end] = temp
            start += 1
            end -= 1
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = k % n
        if k == 0: return
        self.swap(nums, n - k, n - 1)
        self.swap(nums, 0, n - k - 1)
        self.swap(nums, 0, n - 1)

pro = Solution()
nums = [1, 2, 3]
pro.rotate(nums, 1)
for item in nums:
    print(item)