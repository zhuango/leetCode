class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = s.strip()
        try:
            numberS = float(s)
            return True
        except:
            return False

solver = Solution()
print(solver.isNumber("0"))
print(solver.isNumber(" 0.1 "))
print(solver.isNumber("abc"))
print(solver.isNumber("1 a"))
print(solver.isNumber("2e10"))