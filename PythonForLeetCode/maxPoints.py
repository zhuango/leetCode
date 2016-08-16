#!/usr/bin/python3
# Definition for a point.
class Point(object):
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b
from collections import defaultdict
class Solution(object):
    def maxPoints(self, points):
        from collections import defaultdict
        """
        :type points: List[Point]
        :rtype: int
        """
        xDict = defaultdict(lambda:0)
        xDict[0] = 0
        yDict = defaultdict(lambda:0)
        yDict[0] = 0
        hypotenuseDict = defaultdict(lambda : 0)
        hypotenuseDict[0] = 0
        for i in range(len(points)):
            xDict[points[i].x] += 1
            yDict[points[i].y] += 1
            if points[i].y == points[i].x:
                hypotenuseDict[points[i].x / points[i].y] += 1
        maxX = max(xDict.values())
        maxY = max(yDict.values())
        maxH = max(hypotenuseDict.values())
        maxP = max([maxX, maxY, maxH])
        return maxP


points = []
points.append(Point(0,0))
points.append(Point(-1,-1))
points.append(Point(2, 2))
sol = Solution()
result = sol.maxPoints(points)
result = sol.maxPoints([])
print(result)