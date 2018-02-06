# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return head
        bigHead = ListNode(head.val - 1)
        bigHead.next = head
        bigHead2 = ListNode(head.val - 2)
        bigHead2.next = bigHead
        bigHead = bigHead2

        prevprev = bigHead
        prev = prevprev.next
        indexNode = head
        while indexNode != None:

            if indexNode.val == prev.val:
                while indexNode != None and indexNode.val == prev.val:
                    indexNode = indexNode.next
                if indexNode == None:
                    prevprev.next = None
                    break
                else:
                    prev = indexNode
                    prevprev.next = prev
                    indexNode = indexNode.next
            else:
                prevprev = prevprev.next
                prev = indexNode
                indexNode = indexNode.next
        return bigHead.next.next

def printList(result):
    s = ""
    while result != None:
        s += str(result.val) + " "
        result = result.next
    print(s)

l = None
for i in reversed([2]):
    tempNode = ListNode(i)
    tempNode.next = l
    l = tempNode

sol = Solution()
result = sol.deleteDuplicates(l)
printList(result)        