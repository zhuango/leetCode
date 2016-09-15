#!/usr/bin/python3
class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s.strip()
        n = len(s) - 1
        counter = 0
        while n >= 0:
            char = s[n]
            if char == ' ' or char == '\t' or char == '\n':
                return counter
            else:
                counter += 1
            n -= 1
        return counter

pro = Solution()
print(pro.lengthOfLastWord("sfsd \nliuzhuang\t\n"))
print(pro.lengthOfLastWord("liuzhaung"))
print(pro.lengthOfLastWord("liuzhaung is  a student"))
print(pro.lengthOfLastWord(" liuzhaungis a student"))
print(pro.lengthOfLastWord("liuzhaungis a student "))
print(pro.lengthOfLastWord("liuzhaungis a student        "))