#!/usr/bin/python3
class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        from collections import defaultdict
        table = defaultdict(lambda:'_')
        tableNi = defaultdict(lambda:'_')
        for i in range(len(s)):
            if table[s[i]] == '_' and tableNi[t[i]] == '_':
                table[s[i]] = t[i]
                tableNi[t[i]] = s[i]
            else:
                if not table[s[i]] == t[i]:
                    return False
        return True

pro = Solution()
print(pro.isIsomorphic('ab', 'aa'))
print(pro.isIsomorphic("foo", "bar"))
print(pro.isIsomorphic("paper", "title"))
