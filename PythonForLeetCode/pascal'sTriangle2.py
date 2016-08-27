#!/usr/bin/python3
class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        numRows += 1
        oldSingleLevel = [1,1]
        singleLevel = []
        if numRows <= 1:
            return [1]
        if numRows == 2:
            return [1,1]
        i = 3
        while i <= numRows:
            singleLevel = []
            singleLevel.append(1)
            for j in range(i - 2):
                singleLevel.append(oldSingleLevel[j] + oldSingleLevel[j + 1])
            singleLevel.append(1)
            oldSingleLevel = singleLevel
            i += 1
        return singleLevel
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


