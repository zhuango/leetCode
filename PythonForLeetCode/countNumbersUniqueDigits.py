#!/usr/bin/python3
class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 1
        result = 10
        if n > 10:
            n = 10
        i = 2
        while i <= n:
            result += 9 * (self.factorial(9) // self.factorial(9 - i + 1))
            i += 1
        return result
    def factorial(self, n):
        result = 1
        i = 2
        while i <= n:
            result *= i
            i += 1
        return result

pro = Solution()
for i in range(15):
    print(pro.countNumbersWithUniqueDigits(i))