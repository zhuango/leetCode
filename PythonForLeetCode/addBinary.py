#!/usr/bin/python3
class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        result = ""
        carry = 0
        na = len(a) - 1
        nb = len(b) - 1
        while na >= 0 and nb >= 0:
            sum = int(a[na]) + int(b[nb]) + carry
            if sum == 2:
                carry = 1
                result = "0" + result
            elif sum == 3:
                carry = 1
                result = "1" + result
            else:
                result = str(sum) + result
                carry = 0
            na -= 1
            nb -= 1
        if na < 0:
            while nb >= 0:
                sum = int(b[nb]) + carry
                if sum == 2:
                    carry = 1
                    result = "0" + result
                elif sum == 3:
                    carry = 1
                    result = "1" + result
                else:
                    result = str(sum) + result
                    carry = 0
                nb -= 1
        if nb < 0:
            while na >= 0:
                sum = int(a[na]) + carry
                if sum == 2:
                    result = "0" + result
                    carry = 1
                elif sum == 3:
                    result = "1" + result
                    carry = 1
                else:
                    result = str(sum) + result
                    carry = 0
                na -= 1
        if carry == 1:
            result = '1' + result
        return result
pro = Solution()
print(pro.addBinary("11", "1"))
print(pro.addBinary("0", "0"))
print(pro.addBinary("0", "1"))
print(pro.addBinary("1", "1"))
print(pro.addBinary("111", "1"))