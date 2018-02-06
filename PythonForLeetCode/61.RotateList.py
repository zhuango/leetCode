# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head == None or head.next == None:
            return head
        indexNode = head
        length = 0
        while indexNode != None:
            length += 1
            indexNode = indexNode.next
        k = k % length
        if k == 0:
            return head
        indexNode = head
        splitNode = head
        while k > 0:
            indexNode = indexNode.next
            k -= 1
        while indexNode.next != None:
            indexNode = indexNode.next
            splitNode = splitNode.next
        temp = splitNode
        splitNode = splitNode.next
        temp.next = None
        indexNode.next = head
        
        return splitNode
        

def printList(result):
    s = ""
    while result != None:
        s += str(result.val) + " "
        result = result.next
    print(s)

l = None
for i in reversed([1, 2, 3]):
    tempNode = ListNode(i)
    tempNode.next = l
    l = tempNode

sol = Solution()
result = sol.rotateRight(l, 2)
printList(result)        