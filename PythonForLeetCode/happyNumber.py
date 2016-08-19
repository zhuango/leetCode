#!/usr/bin/python3
class Solution(object):
    def getList(self, n):
        result = []
        while not n == 0:
            result.append(n % 10)
            n = n // 10
        return result
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        from collections import defaultdict
        sqSum = n
        appearDig = defaultdict(lambda:False)
        while not sqSum == 1:
            if appearDig[sqSum]:
                return False
            appearDig[sqSum] = True
            temp = 0
            for digit in self.getList(sqSum):
                temp += digit ** 2
            sqSum = temp
            
        return True

sol = Solution()
print(sol.isHappy(123))
print(sol.isHappy(1))
print(sol.isHappy(100))
print(sol.isHappy(19))
