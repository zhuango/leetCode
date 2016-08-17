#!/usr/bin/python3
# Definition for a point.
class Point(object):
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b
from collections import defaultdict
class Solution(object):
    def maxPoints(self, points):
        n = len(points)
        if n < 3:
            return n
        Max = 0
        for i in range(n - Max):
            samep = 1
            j = i + 1
            while j < n:
                if points[i].x == points[j].x and points[i].y == points[j].y:
                    samep += 1
                    continue
                lMax = 1
                k = j + 1
                while k < n:
                    a = (points[i].x - points[k].x)*(points[j].y - points[k].y)
                    b = (points[i].y - points[k].y)*(points[j].x - points[k].x)
                    if a == b:
                        lMax += 1
                    k += 1
                Max = max(Max, lMax + samep)
                j += 1
            i += 1
            Max = max(Max, samep)
        return Max


points = []
points.append(Point(0,0))
points.append(Point(-1,-1))
points.append(Point(2, 2))
sol = Solution()
result = sol.MaxPoints(points)
result = sol.MaxPoints([])
print(result)