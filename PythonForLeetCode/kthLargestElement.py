#!/usr/bin/python3
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        for i in range(k):
            j = i + 1
            maxpos = i
            while j < n:
                if nums[maxpos] < nums[j]:
                    maxpos = j
                j += 1
            temp = nums[i]
            nums[i] = nums[maxpos]
            nums[maxpos] = temp
        return nums[k - 1]
    def findKthLargest2(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        from collections import defaultdict
        n = len(nums)
        map = defaultdict(lambda:0)
        for i in range(n):
            map[nums[i]] += 1
        
        return nums[k - 1]

sol = Solution()
result = sol.findKthLargest([1,2, 3, 4, 5,  6],3)
print(result)
