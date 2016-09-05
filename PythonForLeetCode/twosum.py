#/usr/bin/python3
import time
class Solution(object):
    def twoSum(self, orinums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums= sorted(orinums)
        print(orinums)
        i = 0
        j = 1
        while i < len(nums):
            j = i + 1
            while j < len(nums) and nums[i] + nums[j] <= target:
                if nums[i] + nums[j] == target:
                    index1 = orinums.index(nums[i])
                    orinums.remove(nums[i])
                    index2 = orinums.index(nums[j])
                    if index2 >= index1:
                        index2 += 1
                    return sorted([index1, index2])
                j+=1
            i += 1
        return []
    
    def twoSumOpt(self, orinums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums= sorted(orinums)
        print(orinums)
        i = 0
        j = 1
        while i < len(nums):
            j = i + 1
            while j < len(nums) and nums[i] + nums[j] <= target:
                if nums[i] + nums[j] == target:
                    index1 = orinums.index(nums[i])
                    orinums.remove(nums[i])
                    index2 = orinums.index(nums[j])
                    if index2 >= index1:
                        index2 += 1
                    return sorted([index1, index2])
                j+=1
            i += 1
        return []

sol = Solution()
t0 = time.time()
results = sol.twoSum([-1,-2,-3,-4,-5], -8)
t1 = time.time()
for result in results:
    print(result)
print("take {0} sec".format(t1 - t0))

sol.twoSum([-1,-2,-3,-4,-5], -8)