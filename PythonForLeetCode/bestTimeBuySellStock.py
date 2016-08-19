class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0:
            return 0
        lowestPrice = prices[0]
        max = 0
        n = len(prices)
        for i in range(n):
            if prices[i] < lowestPrice:
                lowestPrice = prices[i]
            elif prices[i] - lowestPrice > max:
                max = prices[i] - lowestPrice
        return max

sol = Solution()
print(sol.maxProfit([7, 1, 5, 3, 6, 4]))
print(sol.maxProfit([7, 6, 4, 3, 1]))

print(sol.maxProfit([1, 1, 1, 1, 1]))
print(sol.maxProfit([1, 1, 1, 2, 1]))
print(sol.maxProfit([23, 2, 9, 2, 213]))