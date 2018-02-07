# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        self.result = None
        length1 = 0
        length2 = 0
        temp = l1
        while temp != None:
            temp = temp.next
            length1 += 1
        temp = l2
        while temp != None:
            temp = temp.next
            length2 += 1
        if length2 > length1:
            l1 ,l2 = l2, l1
            length1, length2 = length2, length1

        templ1 = l1
        for i in range(length1 - length2):
            templ1 = templ1.next
        jinwei = self.ad(templ1, l2)

        length = length1 - length2
        if length != 0 and jinwei != 0:
            newl = ListNode(1)
            length -= 1
        else:
            newl = None
        for i in range(length):
            tempNone = ListNode(0)
            tempNone.next = newl
            newl = tempNone
        if templ1 != l1:
            jinwei = self.ad(newl, l1)
        if jinwei != 0:
            tempNode = ListNode(jinwei)
            tempNode.next = self.result
            self.result = tempNode
        return self.result
    def ad(self, l1, l2):
        if l1 == None or l2 == None:
            return 0
        jinwei = self.ad(l1.next, l2.next)
        curSum = l1.val + l2.val + jinwei
        curBit = int(curSum % 10)
        tempNode = ListNode(curBit)
        tempNode.next = self.result
        self.result = tempNode
        return int(curSum / 10)

l1 = None
for i in [1, 2]:
    tempNode = ListNode(i)
    tempNode.next = l1
    l1 = tempNode
l2 = None
for i in [1]:
    tempNode = ListNode(i)
    tempNode.next = l2
    l2 = tempNode

sol = Solution()
result = sol.addTwoNumbers(l2, l1)

while result != None:
    print(result.val)
    result = result.next