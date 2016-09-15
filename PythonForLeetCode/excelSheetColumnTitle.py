#!/usr/bin/python3
class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        result = ""
        table = {}
        tableNi = {}
        i = 0
        for char in ['', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']:
            table[i] = char
            tableNi[char] = i
            i += 1
        carry = 0
        while n > 0:
            digit = n % 26
            if digit == 0:
                result = "Z" + result
                n = (n - 26) // 26
            else:
                result = table[digit] + result
                n = n // 26
        return result

pro = Solution()
for i in range(26):
    print(pro.convertToTitle(i + 1))
print(pro.convertToTitle(27))
print(pro.convertToTitle(701))
print(pro.convertToTitle(702))
print(pro.convertToTitle(18945))