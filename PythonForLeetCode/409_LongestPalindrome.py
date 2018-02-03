from collections import defaultdict
class Solution:
    def longestPalindrome(self, s):
        char2f = defaultdict(lambda:0)
        for char in s:
            char2f[char] += 1
        result = 0
        hasSingle = False
        for char in char2f:
            canbeUsed = int(char2f[char] / 2) * 2
            result += canbeUsed
            char2f[char] -= canbeUsed
            if char2f[char] != 0:
                hasSingle = True
        if hasSingle:
            return result + 1
        else:
            return result
    def longestPalindromefake(self, s):
        """
        :type s: str
        :rtype: int
        """
        pivot = 1
        n = len(s)
        result = 0
        for pivot in range(n):
            distance = 0
            left = pivot
            right = pivot
            while left >= 0 and right < n and s[left] == s[right]:
                left -= 1
                right += 1
                distance += 1
            if distance * 2 +1 > result:
                result = distance * 2 + 1

            distance = 0
            left = pivot - 1
            right = pivot
            while left >= 0 and right < n and s[left] == s[right]:
                left -= 1
                right += 1
                distance += 1
            if distance * 2 > result:
                result = distance * 2
        return result

sol = Solution()
result = sol.longestPalindrome("abccccdd")
print(result)