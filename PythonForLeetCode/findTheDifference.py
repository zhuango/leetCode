#!/usr/bin/python3
class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        from collections import defaultdict
        table = defaultdict(lambda:0)
        for char in t:
            table[char] += 1
        for char in s:
            table[char] -= 1
        for key in table:
            if table[key] != 0:
                return key

pro = Solution()
print(pro.findTheDifference('sdf', 'sdef'))
print(pro.findTheDifference('', 'a'))
print(pro.findTheDifference('sdf', 'sdefe'))
print(pro.findTheDifference('sdf', 'esdef'))
print(pro.findTheDifference('sdf', 'sdef'))