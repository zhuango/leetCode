#!/usr/bin/python3
class Solution(object):

    def __init__(self, nums):
        import random
        """
        
        :type nums: List[int]
        :type size: int
        """
        self.orignal = list(nums)
        self.sampler = random.Random()

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        return self.orignal
        

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        newArray = []
        n = len(self.orignal)
        for i in self.sampler.sample(list(range(n)), n):
            newArray.append(self.orignal[i])
        return newArray
        


# Your Solution object will be instantiated and called as such:
nums = [1, 2, 3, 4, 5, 6, 7, 8, 9]
obj = Solution(nums)
param_1 = obj.reset()
param_2 = obj.shuffle()
print(param_1)
print(param_2)