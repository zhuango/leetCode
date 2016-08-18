class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        result = []
        k = n // 3
        counter = 0
        candidate = nums[0]
        for i in range(n):
            if counter == 0:
                candidate = nums[i]
            else:
                if nums[i] == candidate:
                    counter += 1
                else:
                    counter -= 1
        # counter = 0
        # for i in range(m):
        #     if nums[i] == candidate:
        #         counter += 1
        # if counter > k:
        #     result.append(candidate)
        
        return candidate

    def majorityElement2(self, nums):
        if not nums:
            return []
        count1, count2, candidate1, candidate2 = 0, 0, 0, 1
        for n in nums:
            if n == candidate1:
                count1 += 1
            elif n == candidate2:
                count2 += 1
            elif count1 == 0:
                candidate1, count1 = n, 1
            elif count2 == 0:
                candidate2, count2 = n, 1
            else:
                count1, count2 = count1 - 1, count2 - 1
        return [n for n in (candidate1, candidate2)
                        if nums.count(n) > len(nums) // 3]
sol = Solution()
result = sol.majorityElement([1, 1, 1,2,2, 3, 3])
print(result)
            