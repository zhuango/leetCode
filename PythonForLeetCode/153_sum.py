from collections import defaultdict
class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        nums = sorted(nums)
        n = len(nums)
        i = 0
        while i < n:
            target = -nums[i]
            front = i + 1
            end = n -1
            while front < end:
                ss = nums[front] + nums[end]
                if ss < target:
                    front += 1
                elif ss > target:
                    end -= 1
                else:
                    triple =[nums[i], nums[front], nums[end]]
                    result.append(triple)
                    while front < end and nums[front] == triple[1]:
                        front += 1
                    while front < end and nums[end] == triple[2]:
                        end -= 1
            while i + 1 < n and nums[i + 1] == nums[i]:
                i+=1
            i+= 1
        return result
        

# "[-1,0,0,0,1,2,-1,-4]"
sol = Solution()
result = sol.threeSum([-1,0,0,0,1,2,-1,-4])
print(result)