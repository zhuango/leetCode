import re
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = re.sub("[ ]+", " ", s)
        revs = "".join(reversed(s.strip()))
        words = revs.split(" ")
        reversedWords = []
        for word in words:
            reversedWords.append("".join(reversed(word)))
        reversedStr = " ".join(reversedWords)

        return reversedStr

sol = Solution()
results = sol.reverseWords("hello world!")
print(results)
results = sol.reverseWords(" ")
print("=="+results + "==")

results = sol.reverseWords("  a     b ")