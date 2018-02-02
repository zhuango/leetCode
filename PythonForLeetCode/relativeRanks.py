class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        dicts = {}
        n = len(nums)
        j = 0
        for i in nums:
            dicts[i] = j
            j += 1
        models = ["Gold Medal", "Silver Medal", "Bronze Medal"]
        numsSorted = sorted(nums, reverse=True)
        strs = ["" for i in range(n)]
        j = 4

        i = 1
        cond = min(3, n)
        while i <= cond:
            strs[dicts[numsSorted[i - 1]]] = models[i - 1]
            i += 1
        
        i = 3
        while i < n:
            strs[dicts[numsSorted[i]]] = str(i + 1)
            i += 1
        return strs

sol = Solution()

result = sol.findRelativeRanks([2])
print(result)
result = sol.findRelativeRanks([3, 2])
print(result)
result = sol.findRelativeRanks([2, 3])
print(result)

result = sol.findRelativeRanks([20, 2, 4])
print(result)

result = sol.findRelativeRanks([20, 2, 4, 3])
print(result)