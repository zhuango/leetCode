#/usr/bin/python
class Solution(object):
    def __init__(self):
        self.results = []
        self.stack = []
        self.sum = 0
        self.len = 0
    def track(self, condidates, index, target):
        if not condidates[index] == 0:
            self.sum += condidates[index]
            self.stack.append(condidates[index])
        else:
            index += 1

        if self.sum == target:
            self.results.append(list(self.stack))
        if self.sum < target:
            i = index
            while i < self.len:
                self.track(condidates, i, target)
                i+=1
        if not len(self.stack) == 0:
            del self.stack[-1]
            self.sum -= condidates[index]


    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        if candidates == None or len(candidates) == 0:
            return []
        candidates = sorted(candidates)
        candidates.insert(0, 0)
        self.len = len(candidates)
        self.track(candidates, 0, target)
        return self.results
        
solver = Solution()
print(solver.combinationSum([2, 3, 6, 7], 7))
solver = Solution()
print(solver.combinationSum([1, 2, 3], 4))
solver = Solution()
print(solver.combinationSum([1], 1))
solver = Solution()
print(solver.combinationSum([2,3,6,7], 100))