#!/usr/bin/python3
class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        result = []
        if numRows <= 0:
            return []
        result.append([1])
        if numRows == 1:
            return result
        result.append([1, 1])
        if numRows == 2:
            return result
        i = 3
        while i <= numRows:
            singleLevel = []
            singleLevel.append(1)
            for j in range(i - 2):
                singleLevel.append(result[i - 2][j] + result[i - 2][j + 1])
            singleLevel.append(1)
            result.append(singleLevel)
            i += 1
        return result
sol = Solution()
print(sol.generate(0))
for level in sol.generate(1):
    print(level)
for level in sol.generate(2):
    print(level)
for level in sol.generate(3):
    print(level)
for level in sol.generate(4):
    print(level)
for level in sol.generate(10):
    print(level)


