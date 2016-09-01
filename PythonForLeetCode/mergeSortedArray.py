#!/usr/bin/python3
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        curMax = m + n - 1
        m -= 1
        n -= 1
        while m >= 0 and n >= 0:
            if nums1[m] > nums2[n]:
                nums1[curMax] = nums1[m]
                m -= 1
                curMax -= 1
            else:
                nums1[curMax] = nums2[n]
                n -= 1
                curMax -= 1
        if n >= 0:
            while n >= 0:
                nums1[curMax] = nums2[n]
                curMax -= 1
                n -= 1
        return nums1

pro = Solution()
for i in pro.merge([1], 1, [], 0):
    print(i)