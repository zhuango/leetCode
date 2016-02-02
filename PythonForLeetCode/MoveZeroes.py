def moveZeroes(nums):
    """
    :type nums: List[int]
    :rtype: void Do not return anything, modify nums in-place instead.
    """
    pos = 0
    for i in range(len(nums)):
        if(int(nums[i]) != 0):
            nums[pos] = nums[i]
            pos += 1
    else :
        if pos < len(nums):
            j = pos
            while j < len(nums):
                nums[j] = 0
                j += 1
    return IsAllZero(pos, nums)
def IsAllZero(start, nums):
    if start == len(nums): return True
    for i in [start, len(nums) - 1]:
        if(nums[i]):
           return False
    else:
        return True
print(moveZeroes([0,1,0,3,12]))
print(moveZeroes([1, 0, 0, 0, 0]))
print(moveZeroes([1, 1, 1, 0, 0]))
print(moveZeroes([]))
print(moveZeroes([4,2,4,0,0,3,0,5,1,0]))