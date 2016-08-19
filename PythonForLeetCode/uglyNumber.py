#!/usr/bin/python3
class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num == 0:
            return False
        if num == 1:
            return True
        uglyFactor = [2, 3, 5]
        while not num == 1:
            isDivided = False
            for factor in uglyFactor:
                if num % factor == 0:
                    num  = num // factor
                    isDivided = True
                    break
            if not isDivided:
                return False
        return True

sol = Solution()
print(sol.isUgly(0))
print(sol.isUgly(1))
print(sol.isUgly(2))
print(sol.isUgly(3))
print(sol.isUgly(4))
print(sol.isUgly(5))
print(sol.isUgly(6))
print(sol.isUgly(8))
print(sol.isUgly(14))
print(sol.isUgly(-6))