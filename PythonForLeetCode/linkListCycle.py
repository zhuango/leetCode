#!/usr/bin/python3

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def hasCycleMa(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head == None:
            return False
        from collections import defaultdict
        idTable = defaultdict(lambda:False)
        idTable[id(head)] = True
        head = head.next
        while not head == None:
            if idTable[id(head)]:
                return True
            idTable[id(head)] = True
            head = head.next
        return False
    def hasCycle(self, head):
        if head == None:
            return False
        slow = head
        if head.next == None:
            return False
        fast = head.next.next
        while not fast == None:
            if slow == fast:
                return True
            slow = slow.next
            if fast.next == None :
                return False
            else:
                fast = fast.next.next
        return False

    def detectCycle(self, head):
        cycleNode = None
        if head == None:
            return None
        slow = head
        if head.next == None:
            return None
        fast = head.next.next
        while not fast == None:
            if slow == fast:
                cycleNode = slow
                break
            slow = slow.next
            if fast.next == None :
                return None
            else:
                fast = fast.next.next
        if cycleNode == None: return None
        index = head
        while not index == None:
            if index == cycleNode: return index
            cycleIndex = cycleNode.next
            while not cycleIndex == cycleNode:
                if cycleIndex == index: return index
                cycleIndex = cycleIndex.next
            index = index.next
        return None

head = None
for i in range(7):
    newNode = ListNode(i)
    newNode.next = head
    head = newNode

struggleNode = head.next.next
head.next.next.next.next.next = struggleNode

sol = Solution()
print((sol.detectCycle(head)).val)
print(sol.detectCycle(None))
head = None
for i in range(7):
    newNode = ListNode(i)
    newNode.next = head
    head = newNode
print(sol.detectCycle(head))
