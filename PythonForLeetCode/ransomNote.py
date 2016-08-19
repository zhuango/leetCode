#!/usr/bin/python3
class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        from collections import defaultdict
        letterTable = defaultdict(lambda:0)
        for letter in magazine:
            letterTable[letter] += 1
        for letter in ransomNote:
            letterTable[letter] -= 1
            if letterTable[letter] < 0:
                return False
        return True


sol = Solution()
result = sol.canConstruct('aa', 'aab')
print(result)

result = sol.canConstruct('ab', 'a')
print(result)

result = sol.canConstruct("aa", "ab")
print(result)

result = sol.canConstruct("abc", "abc")
print(result)