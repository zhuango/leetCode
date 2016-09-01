#!/usr/bin/python3
class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        first = abs(C - A) * abs(D - B)
        second= abs(G - E) * abs(H - F)
        firstInSecond = []
        for x in (A, C):
            for y in (B, D):
                if x >= E and x <= G and y >= F and y <= H:
                    firstInSecond.append([x, y])
        secondInFirst = []
        for x in (E, G):
            for y in (F, H):
                if x >= A and x <= C and y >= B and y <= D:
                    secondInFirst.append([x, y])
        n1 = len(firstInSecond)
        n2 = len(secondInFirst)
        if n1 == 0 and n2 == 0:
            if B > F and B < H and D > F and D < H and E > A and E < C and G > A and G < C:
                return first + second - (G - E) * (D - B)
            if F > B and F < D and H > B and H < D and A > E and A < G and C > E and C < G:
                return first + second - (C - A) * (H - F)
            return first + second
        if n1 == 1 and n2 == 1:
            p1 = firstInSecond[0]
            p2 = secondInFirst[0]
            return first + second - abs(p1[0] - p2[0]) * abs(p1[1] - p2[1])
        if n1 == 2 and n2 < 2:
            firstP1 = firstInSecond[0]
            secndP1 = firstInSecond[1]
            if firstP1[0] == secndP1[0]:
                if A < E:
                    return first + second - (abs(firstP1[1] - secndP1[1])) * (firstP1[0] - E)
                else:
                    return first + second - (abs(firstP1[1] - secndP1[1])) * (G - firstP1[0])
            else:
                if D <= H:
                    return first + second - (abs(firstP1[0] - secndP1[0])) * (firstP1[1] - F)
                else:
                    return first + second - (abs(firstP1[0] - secndP1[0])) * (H - firstP1[1])
        if n1 < 2 and n2 == 2:
            firstP1 = secondInFirst[0]
            secndP1 = secondInFirst[1]
            if firstP1[0] == secndP1[0]:
                if E < A:
                    return first + second - (abs(firstP1[1] - secndP1[1])) * (firstP1[0] - A)
                else:
                    return first + second - (abs(firstP1[1] - secndP1[1])) * (C - firstP1[0])
            else:
                if H <= D:
                    return first + second - (abs(firstP1[0] - secndP1[0])) * (firstP1[1] - B)
                else:
                    return first + second - (abs(firstP1[0] - secndP1[0])) * (D - firstP1[1])
        if n1 == 2 and n2 == 2:
            for point in firstInSecond:
                if point in secondInFirst:
                    firstInSecond.remove(point)
                    secondInFirst.remove(point)
                    p1 = firstInSecond[0]
                    p2 = secondInFirst[0]
                    return first + second - abs(p1[0] - p2[0]) * abs(p1[1] - p2[1])

            p1 = firstInSecond[0]
            if secondInFirst[0][0] == p1[0] or \
               secondInFirst[0][1] == p1[1]:
                p2 = secondInFirst[1]
            else:
                p2 = secondInFirst[0]
            return first + second - abs(p1[0] - p2[0]) * abs(p1[1] - p2[1])
        if n1 == 4:
            return second
        if n2 == 4:
            return first 
        return -1
    def computeArea_Smart(self, A, B, C, D, E, F, G, H):
        first = (C - A) * (D - B)
        second= (G - E) * (H - F)
        if A>=G or B >= H or E>= C or F>= D:
            return first + second
        else:
            return first + second - (min(C, G) - max(A, E)) * (min(H, D) - max(B, F))
pro = Solution()
print(pro.computeArea(-5, -3, 3, 0, -3, -3, 3, 3))

print(pro.computeArea(-3, 0, 3, 4, 0, -1, 9, 2))
print(pro.computeArea(3, 0, 10, 4, 0, -1, 9, 2))
print(pro.computeArea(3, -2, 10, 1, 0, -1, 9, 2))
print(pro.computeArea(-3, -2, 3, 1, 0, -1, 9, 2))

print(pro.computeArea(-3, 0, 3, 2, 0, -1, 9, 2))
print(pro.computeArea(-3, 0, 3, 1, 0, -1, 9, 2))
print(pro.computeArea(-3, -1, 3, 1, 0, -1, 9, 2))
print(pro.computeArea(1, 0, 10, 2, 0, -1, 9, 2))
print(pro.computeArea(1, 0, 10, 1, 0, -1, 9, 2))
print(pro.computeArea(1, -1, 10, 1, 0, -1, 9, 2))
print(pro.computeArea(0, 0, 8, 4, 0, -1, 9, 2))
print(pro.computeArea(3, 0, 8, 4, 0, -1, 9, 2))
print(pro.computeArea(3, 0, 9, 4, 0, -1, 9, 2))
print(pro.computeArea(0, -2, 8, 0, 0, -1, 9, 2))
print(pro.computeArea(3, -2, 8, 0, 0, -1, 9, 2))
print(pro.computeArea(3, -2, 9, 0, 0, -1, 9, 2))

print(pro.computeArea(0, -1, 9, 2, -3, 0, 3, 2))
print(pro.computeArea(0, -1, 9, 2, -3, 0, 3, 1))
print(pro.computeArea(0, -1, 9, 2, -3, -1, 3, 1))
print(pro.computeArea(0, -1, 9, 2, 1, 0, 10, 2))
print(pro.computeArea(0, -1, 9, 2, 1, 0, 10, 1))
print(pro.computeArea(0, -1, 9, 2, 1, -1, 10, 1))
print(pro.computeArea(0, -1, 9, 2, 0, 0, 8, 4))
print(pro.computeArea(0, -1, 9, 2, 3, 0, 8, 4))
print(pro.computeArea(0, -1, 9, 2, 3, 0, 9, 4))
print(pro.computeArea(0, -1, 9, 2, 0, -2, 8, 0))
print(pro.computeArea(0, -1, 9, 2, 3, -2, 8, 0))
print(pro.computeArea(0, -1, 9, 2, 3, -2, 9, 0))

print(pro.computeArea(0, 0, 9, 4, 0, -1, 9, 2))
print(pro.computeArea(0, -2, 9, 0, 0, -1, 9, 2))
print(pro.computeArea(-3, -1, 3, 2, 0, -1, 9, 2))
print(pro.computeArea(1, -1, 10, 2, 0, -1, 9, 2))

print(pro.computeArea(1, 0, 8, 1, 0, -1, 9, 2))
print(pro.computeArea(-3, -2, 10, 4, 0, -1, 9, 2))

print(pro.computeArea(-3,-5,0,5,-3,-3,3,3))
# -5
# 0
# 5
# 3
# -3
# -3
# 3
# 3