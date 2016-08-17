#!/usr/bin/python3
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        isPositive = True
        result = 0
        #muler = 1
        if x < 0:
            isPositive = False
            x = -x
        while not x == 0:
            digit = x % 10
            x = x / 10
            result = result * 10 + digit
            #muler *= 10
        if isPositive:
            return  result
        else:
            return -result
sol = Solution()
result = sol.reverse(12345678)
print(result)