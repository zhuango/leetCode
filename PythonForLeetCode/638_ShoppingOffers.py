class Solution:
    def shoppingOffers(self, price, special, needs):
        """
        :type price: List[int]
        :type special: List[List[int]]
        :type needs: List[int]
        :rtype: int
        """
        result = 0
        count = 0
        for need in needs:
            result += need * price[count]
            count += 1
        itemSize = len(price)
        specResult = result
        for spec in special:
            needNext = []
            count = 0
            for need in needs:
                tempNeed = need - spec[count]
                if tempNeed < 0:
                    needNext = []
                    break
                needNext.append(tempNeed)
                count += 1
            if needNext:
                tempResult = spec[-1]
                tempResult += self.shoppingOffers(price, special, needNext)
                if tempResult < specResult:
                    specResult = tempResult
        return min(result, specResult)

sol = Solution()
result = sol.shoppingOffers([2,5], [[3,0,5],[1,2,10]], [3,2])
print(result)
result = sol.shoppingOffers([2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1])
print(result)