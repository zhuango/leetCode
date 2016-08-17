#!/usr/bin/python3

class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        if n == 0 or s[0] == '0':
            return 0
        table = [0 for i in range(n + 1)]
        table[0] = 1
        table[1] = 1
        if(s[-1] == '0'):
            table[1] = 0
        i = 2
        while i <= n:
            curDig = int(s[-i])
            if  curDig == 1 or \
                (curDig == 2 and int(s[-i + 1]) <= 6):
                table[i] = table[i - 2] + table[i - 1]
            elif curDig == 0:
                table[i] = 0
            else:
                table[i] = table[i - 1]
            i += 1
        return table[n]
sol = Solution()
result = sol.numDecodings("1029")
print(result)
