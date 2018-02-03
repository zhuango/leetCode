class Solution:
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        result = []
        for i in range(left, right + 1):
            temp = i
            divide = True
            while temp > 0:
                mode = temp % 10
                if mode == 0 or i % mode != 0:
                    divide = False
                temp = int(temp / 10)
            if divide:
                result.append(i)
        return result

sol = Solution()
result = sol.selfDividingNumbers(1, 22)
print(result)


            
            