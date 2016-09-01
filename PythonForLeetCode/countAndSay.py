#!/usr/bin/python3
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        result = '1'
        for i in range(n - 1):
            newStr = ''
            tempChar = result[0]
            counter = 0
            for char in result:
                if char == tempChar:
                    counter += 1
                else:
                    newStr += str(counter) + tempChar
                    counter = 1
                    tempChar = char
            newStr += str(counter) + tempChar
            result = newStr
        return result

pro = Solution()
for i in range(10):
    print(pro.countAndSay(i))
                