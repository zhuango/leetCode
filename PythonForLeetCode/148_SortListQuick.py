# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        bigHead = ListNode(-1)
        bigHead.next = head
        tempNode = head
        length = 0
        return self.sort(bigHead, None)
    def sort(self, l1, l2):
        if l1.next is l2:
            return l1.next
        l1Next, mid = self.part(l1.next, l2)
        l1.next = l1Next
        l1.next = self.sort(l1, mid)
        mid.next = self.sort(mid, l2)
        return l1.next
    def part(self, l1, l2):
        if l1 is l2:
            return l1, l2
        mid = l1
        l1 = l1.next
        mid.next = None
        sortedList1 = mid
        sortedList2 = l2
        while l1 is not l2:
            tempNode = l1
            l1 = l1.next
            if tempNode.val < mid.val:
                tempNode.next = sortedList1
                sortedList1 = tempNode
            else:
                tempNode.next = sortedList2
                sortedList2 = tempNode
        mid.next = sortedList2
        return sortedList1, mid

def printList(result):
    s = ""
    while result != None:
        s += str(result.val) + " "
        result = result.next
    print(s)

l = None
for i in range(0, 997):
    tempNode = ListNode(i)
    tempNode.next = l
    l = tempNode

sol = Solution()
result = sol.sortList(l)
#lnext, mid = sol.part(l.next, l.next.next.next.next)
#l.next = lnext
printList(result)
#print("=================")
#printList(mid)