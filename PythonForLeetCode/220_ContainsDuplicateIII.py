class Solution:
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        newlist = []
        count = 0
        for num in nums:
            newlist.append([num, count])
            count += 1
        newlist = list(sorted(newlist, key=lambda x:x[0]))
        n = len(newlist)
        i = 0
        while i < n:
            start = newlist[i]
            j = i + 1
            while j < n:
                end = newlist[j]
                dif = abs(start[0] - end[0])
                if dif > t:
                    break
                if abs(start[1] - end[1]) <= k:
                    return True
                j += 1
            i += 1
        return False
                
sol = Solution()
result = sol.containsNearbyAlmostDuplicate([2, 1, 43, 675, 3, 63, 34, 4], 0, 0)
print(result)