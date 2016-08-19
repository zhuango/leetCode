#!/usr/bin/python3
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        table = [0 for i in range(n + 2)]
        table[0] = 1
        table[1] = 1
        i = 2
        while i <= n:
            table[i] = table[i - 1] + table[i - 2]
            i += 1
        return table[n]
sol = Solution()
print(sol.climbStairs(0))
print(sol.climbStairs(1))
print(sol.climbStairs(2))
print(sol.climbStairs(10))

print(sol.climbStairs(99))
print(sol.climbStairs(100))
print(sol.climbStairs(101))