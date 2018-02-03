from collections import defaultdict
class Solution:
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        char2f = defaultdict(lambda : 0)
        n = len(s) + 1
        f2char = [[] for i in range(n)]
        for char in s:
            char2f[char] += 1
        for key in char2f:
            f2char[char2f[key]].append(key)
        result = ""
        print(char2f)
        for i in range(n - 1, -1, -1):
            for char in f2char[i]:
                result += (char * i)
        return result

sol = Solution()
result = sol.frequencySort("tree")
print(result)

result = sol.frequencySort("cccaaa")
print(result)
