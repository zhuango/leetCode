#!/usr/bin/python3
class Solution(object):
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        table = {1:0}
        i = 2
        while i <= n:
            if i not in table:
                if i % 2 == 0:
                    table[i] = table[i // 2] + 1
                else:
                    a = table[(i + 1) // 2] + 2
                    b = table[(i - 1) // 2] + 2
                    if a > b:
                        a = b
                    else:
                        table[i + 1] = a - 1
                    table[i] = a
            i += 1
        return table[n]
    def integerReplacement2(self, n):
        memo = {1 : 0}
        def helper(m):
            if m not in memo:
                # From an odd number m, you must jump to (m - 1) / 2 or (m + 1) / 2 using two steps
                memo[m] = helper(m // 2) + 1 if m % 2 == 0 else min(helper((m - 1) / 2), helper((m + 1) / 2)) + 2
            return memo[m]
        return helper(n)

sol = Solution()
print(sol.integerReplacement(1))
print(sol.integerReplacement(2))
print(sol.integerReplacement(3))
print(sol.integerReplacement(4))
print(sol.integerReplacement(8))
print(sol.integerReplacement(7))
print(sol.integerReplacement2(10000000))