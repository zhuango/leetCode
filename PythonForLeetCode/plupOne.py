#!/usr/bin/python3

class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        result = []
        highBit = 1
        n = len(digits)
        if n == 0:
            result.append(1)
            return result
        i = n - 1
        while i >= 0:
            digits[i] += highBit
            if digits[i] >= 10:
                highBit = 1
                digits[i] = digits[i] - 10
            else:
                highBit = 0
                break
            i -= 1
        if highBit == 1:
            result.append(1)
        for i in digits:
            result.append(i)
            i += 1
        return result

sol = Solution()
print(sol.plusOne([1, 2,3]))
print(sol.plusOne([0]))
print(sol.plusOne([9]))
print(sol.plusOne([9, 9, 9, 9, 9]))
print(sol.plusOne([9, 9, 9, 8, 9]))