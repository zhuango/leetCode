#!/usr/bin/python3
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):
def isBadVersion(number):
    if number >= 2:
        return True
    else:
        return False
class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        start = 1
        end = n
        while start <= end:
            middle = (start + end) // 2 
            if isBadVersion(middle):
                if not isBadVersion(middle - 1):
                    return middle
                end = middle - 1
            else:
                start = middle + 1

        return 0
sol = Solution()
print(sol.firstBadVersion(2))