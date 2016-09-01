#!/usr/bin/python3
# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):
def guess(num):
    picked = 10
    if   num > picked:
        return 1
    elif num < picked:
        return -1
    else:
        return 0
class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        high = n
        low  = 1
        while low <= high:
            middle = (low + high) // 2
            compToPicked = guess(middle)
            if   compToPicked < 0:
                low  = middle + 1
            elif compToPicked > 0:
                high = middle - 1
            else:
                return middle
        return 0
pro = Solution()
print(pro.guessNumber(10))