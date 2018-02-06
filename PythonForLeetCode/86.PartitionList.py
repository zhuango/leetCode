# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        indexNode = head
        greater = ListNode(-1)
        less = ListNode(-1)
        tailGreater = greater
        tailLess = less
        while indexNode != None:
            tempNode = indexNode
            indexNode = indexNode.next
            if tempNode.val < x:
                tailLess.next = tempNode
                tailLess = tempNode
            else:
                tailGreater.next = tempNode
                tailGreater = tempNode
        tailLess.next = greater.next
        tailGreater.next = None
        return less.next

def printList(result):
    s = ""
    while result != None:
        s += str(result.val) + " "
        result = result.next
    print(s)

l = None
for i in reversed([9, 4]):
    tempNode = ListNode(i)
    tempNode.next = l
    l = tempNode

sol = Solution()
result = sol.partition(l, 6)
printList(result)        