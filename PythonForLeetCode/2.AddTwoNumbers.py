# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        result = ListNode(-1)
        tail = result
        jinwei = 0
        while l1 != None and l2 != None:
            su = l1.val + l2.val + jinwei
            jinwei = int(su / 10)
            tempNode = ListNode(int(su % 10))
            tail.next = tempNode
            tail = tempNode
            l1 = l1.next
            l2 = l2.next
        l = None
        if l1 != None:
            l = l1
        if l2 != None:
            l = l2
        while l != None:
            su = l.val + jinwei
            jinwei = int(su/10)
            tempNode = ListNode(int(su%10))
            tail.next = tempNode
            tail = tempNode
            l = l.next
        if jinwei != 0:
            tempNode = ListNode(jinwei)
            tail.next = tempNode
            tail = tempNode

        return result.next

def printList(result):
    s = ""
    while result != None:
        s += str(result.val) + " "
        result = result.next
    print(s)

l = None
for i in reversed([9, 9, 7, 9]):
    tempNode = ListNode(i)
    tempNode.next = l
    l = tempNode

l2 = None
for i in reversed([1, 2]):
    tempNode = ListNode(i)
    tempNode.next = l2
    l2 = tempNode

sol = Solution()
result = sol.addTwoNumbers(l, l2)
printList(result)        