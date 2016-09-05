#!/usr/bin/python3
class Solution(object):
    def reverseBits(self, n):
        """
        :type n: int
        :rtype: int
        """
        newNumber = 0
        for i in range(32):
            bit = n % 2
            newNumber = newNumber * 2 + bit
            n = n // 2
        return newNumber

pro = Solution()
print(pro.reverseBits(43261596))
print(pro.reverseBits(964176192))