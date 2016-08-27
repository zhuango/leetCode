#!/usr/bin/python3
class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        ex = 0
        divider = 5
        while n >= divider:
            ex += 1
            divider *= 5
        counter = 0
        divider /= 5
        while divider > 1:
            counter += n // divider
            divider /= 5
        return counter
sol = Solution()
print(sol.trailingZeroes(0))
print(sol.trailingZeroes(1))
print(sol.trailingZeroes(2))
print(sol.trailingZeroes(100))
print(sol.trailingZeroes(25))
print(sol.trailingZeroes(32))
