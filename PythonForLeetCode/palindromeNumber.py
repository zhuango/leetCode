#!/usr/bin/python3
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        temp = x
        new = 0
        while temp > 0:
            new = new * 10 + temp%10
            temp = temp // 10
        return new == x
sol = Solution()
print(sol.isPalindrome(1))
print(sol.isPalindrome(0))
print(sol.isPalindrome(1))
print(sol.isPalindrome(112))
print(sol.isPalindrome(11))
print(sol.isPalindrome(121))
print(sol.isPalindrome(123321))