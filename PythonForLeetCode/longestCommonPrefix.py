#!/usr/bin/python3
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ""
        result = ""
        n = len(strs[0])
        for item in strs:
            curLength = len(item)
            if curLength < n:
                n = curLength
        for i in range(n):
            curChar = strs[0][i]
            for item in strs:
                if not item[i] == curChar:
                    return result
            result += curChar
        return result

pro = Solution()
print(pro.longestCommonPrefix([' qw', ' ew', ' re', ' we']) + "***")
print(pro.longestCommonPrefix(['wwrs', 'wwresf', 'wwre', 'wwrE']))