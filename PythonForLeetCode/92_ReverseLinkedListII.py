# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        if m == n:
            return head
        bigHead = ListNode(-1)
        bigHead.next = head
        
        prev = bigHead
        rangeStart = head
        rangeList = None

        count = 0
        while rangeStart != None:
            count += 1
            if count == m:
                break
            prev = rangeStart
            rangeStart = rangeStart.next
        
        prev.next = None
        rangeEnd = rangeStart
        endofRange = rangeEnd
        while rangeEnd != None:
            temp = rangeEnd
            rangeEnd = rangeEnd.next
            temp.next = rangeList
            rangeList = temp

            count += 1
            if count == n + 1:
                break
        prev.next = rangeList
        endofRange.next = rangeEnd
        return bigHead.next
def printList(result):
    s = ""
    while result != None:
        s += str(result.val) + " "
        result = result.next
    print(s)

l = None
for i in reversed([-10,-3,0,5,9]):
    tempNode = ListNode(i)
    tempNode.next = l
    l = tempNode

sol = Solution()
result = sol.reverseBetween(l, 4, 5)
printList(result)        