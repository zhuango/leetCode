#!/usr/bin/python

def IsMax2(a,b):
    na = 0
    nb = 0
    tempa = a
    tempb = b
    abits = []
    bbits = []
    if a == 0:
        abits.append(0)
        na += 1
    if b == 0:
        bbits.append(0)
        nb += 1
    # print(a, b)
    while a != 0:
        abits.insert(0, a % 10)
        a = a / 10
        na += 1
    while b != 0:
        bbits.insert(0, b % 10)
        b = b / 10
        nb += 1
    n = min([nb, na])
    for i in range(n):
        if abits[i] == bbits[i]:
            continue
        if abits[i] > bbits[i]:
            return 1
        else:
            return -1
    a_b = tempa * pow(10, (nb)) + tempb
    b_a = tempb * pow(10, (na)) + tempa
    print(a_b)
    print(b_a)
    if a_b > b_a:
        return 1
    elif a_b < b_a:
        return -1
    else:
        return 0
class Solution:
    # @param {integer[]} nums
    # @return {string}
        
    def largestNumber(self, nums):
        strs = ""
        n = len(nums)
        nums = sorted(nums, cmp=IsMax2, reverse=True)
        # print(nums)
        i = 0
        while i < n and nums[i] == 0:
            i += 1
        if i == n:
            return "0"
        while i < n:
            strs += str(nums[i])
            i+=1
    
        return strs
sol = Solution()
result = sol.largestNumber([824,938,1399,5607,6973,5703,9609,4398,8247])
#print(IsMax(3,34))
print(result)
print("9609938824824769735703560743981399")
print(" ".join(result) == "9609 938 824 8247 6973 5703 5607 4398 1399")

print("===================")
result = sol.largestNumber([128,12])
print(result)

result = sol.largestNumber([0,9,8,7,6,5,4,3,2,1])
print(result)
