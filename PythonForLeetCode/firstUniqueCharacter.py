#!/usr/bin/python3
class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        from collections import defaultdict
        table = defaultdict(lambda:0)
        for char in s:
            table[char] += 1
        for i in range(len(s)):
            if table[s[i]] == 1:
                return i 

sol = Solution()
print(sol.firstUniqChar('liuzhuang'))
print(sol.firstUniqChar('leetcode'))
print(sol.firstUniqChar('loveleetcode'))