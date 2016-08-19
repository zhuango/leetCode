#!/usr/bin/python3
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """        
        from collections import defaultdict
        letterTable = defaultdict(lambda:0)
        for letter in s:
            letterTable[letter] += 1
        for letter in t:
            letterTable[letter] -= 1
        for key in letterTable:
            if letterTable[key] != 0:
                return False
        return True
        
sol = Solution()
result = sol.isAnagram("anagram",  "nagaram")
print(result)

result = sol.isAnagram("rat",  "cat")
print(result)

result = sol.isAnagram("",  "")
print(result)

result = sol.isAnagram("abcdef",  "abcdeff")
print(result)

result = sol.isAnagram("abcdeff",  "abcdef")
print(result)