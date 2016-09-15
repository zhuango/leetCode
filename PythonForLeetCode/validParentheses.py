#!/usr/bin/python3
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        counter = 0
        pair = {')':'(', ']':'[', '}':'{'}
        table = {'(':True, '[':True, '{':True, '}': False, ']': False, ')': False}
        for char in s:
            if table[char]:
                stack.append(char)
                counter += 1
            else:
                if counter == 0:
                    return False
                endPos = counter - 1
                if stack[endPos] == pair[char]:
                    del stack[endPos]
                    counter -= 1
                else:
                    return False
        if not counter == 0:
            return False
        return True

pro = Solution()
print(pro.isValid(')()()(()){{}}'))
print(pro.isValid(')'))
print(pro.isValid('{}]'))
print(pro.isValid('({}){'))
print(pro.isValid('((({{}()}(()))))'))